//$file${src::qf::qf_dyn.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: qpcpp.qm
// File:  ${src::qf::qf_dyn.cpp}
//
// This code has been generated by QM 5.3.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This code is covered by the following QP license:
// License #    : LicenseRef-QL-dual
// Issued to    : Any user of the QP/C++ real-time embedded framework
// Framework(s) : qpcpp
// Support ends : 2024-12-31
// License scope:
//
// Copyright (C) 2005 Quantum Leaps, LLC <state-machine.com>.
//
//                    Q u a n t u m  L e a P s
//                    ------------------------
//                    Modern Embedded Software
//
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
//
// This software is dual-licensed under the terms of the open source GNU
// General Public License version 3 (or any later version), or alternatively,
// under the terms of one of the closed source Quantum Leaps commercial
// licenses.
//
// The terms of the open source GNU General Public License version 3
// can be found at: <www.gnu.org/licenses/gpl-3.0>
//
// The terms of the closed source Quantum Leaps commercial licenses
// can be found at: <www.state-machine.com/licensing>
//
// Redistributions in source code must retain this top-level comment block.
// Plagiarizing this software to sidestep the license obligations is illegal.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${src::qf::qf_dyn.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#define QP_IMPL             // this is QP implementation
#include "qp_port.hpp"      // QP port
#include "qp_pkg.hpp"       // QP package-scope interface
#include "qsafe.h"          // QP Functional Safety (FuSa) Subsystem
#ifdef Q_SPY                // QS software tracing enabled?
    #include "qs_port.hpp"  // QS port
    #include "qs_pkg.hpp"   // QS facilities for pre-defined trace records
#else
    #include "qs_dummy.hpp" // disable the QS software tracing
#endif // Q_SPY

#if (QF_MAX_EPOOL > 0U)     // mutable events configured?

// unnamed namespace for local definitions with internal linkage
namespace {
Q_DEFINE_THIS_MODULE("qf_dyn")
} // unnamed namespace

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${QF::QF-dyn} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace QP {
namespace QF {

//${QF::QF-dyn::poolInit} ....................................................
void poolInit(
    void * const poolSto,
    std::uint_fast32_t const poolSize,
    std::uint_fast16_t const evtSize) noexcept
{
    std::uint_fast8_t const poolId = priv_.maxPool_;

    // see precondition{qf_dyn,200} and precondition{qf_dyn,201}
    QF_CRIT_STAT
    QF_CRIT_ENTRY();
    QF_MEM_SYS();

    Q_REQUIRE_INCRIT(200, poolId < QF_MAX_EPOOL);
    if (poolId > 0U) {
        Q_REQUIRE_INCRIT(201,
            QF_EPOOL_EVENT_SIZE_(priv_.ePool_[poolId - 1U]) < evtSize);
    }
    priv_.maxPool_ = poolId + 1U; // one more pool

    QF_MEM_APP();
    QF_CRIT_EXIT();

    // perform the port-dependent initialization of the event-pool
    QF_EPOOL_INIT_(priv_.ePool_[poolId], poolSto, poolSize, evtSize);

    #ifdef Q_SPY
    // generate the object-dictionary entry for the initialized pool
    {
        std::uint8_t obj_name[9] = "EvtPool?";
        obj_name[7] = static_cast<std::uint8_t>(
            static_cast<std::uint8_t>('0')
            + static_cast<std::uint8_t>(poolId + 1U));
        QS_CRIT_ENTRY();
        QS_MEM_SYS();
        QS::obj_dict_pre_(&priv_.ePool_[poolId],
                          reinterpret_cast<char *>(&obj_name[0]));
        QS_MEM_APP();
        QS_CRIT_EXIT();
    }
    #endif // Q_SPY
}

//${QF::QF-dyn::poolGetMaxBlockSize} .........................................
std::uint_fast16_t poolGetMaxBlockSize() noexcept {
    return QF_EPOOL_EVENT_SIZE_(priv_.ePool_[priv_.maxPool_ - 1U]);
}

//${QF::QF-dyn::getPoolMin} ..................................................
std::uint_fast16_t getPoolMin(std::uint_fast8_t const poolId) noexcept {
    QF_CRIT_STAT
    QF_CRIT_ENTRY();
    QF_MEM_SYS();

    Q_REQUIRE_INCRIT(400, (poolId <= QF_MAX_EPOOL)
                      && (0U < poolId) && (poolId <= priv_.maxPool_));

    std::uint_fast16_t const min = static_cast<std::uint_fast16_t>(
        priv_.ePool_[poolId - 1U].getNMin());

    QF_MEM_APP();
    QF_CRIT_EXIT();

    return min;
}

//${QF::QF-dyn::newX_} .......................................................
QEvt * newX_(
    std::uint_fast16_t const evtSize,
    std::uint_fast16_t const margin,
    enum_t const sig) noexcept
{
    QF_CRIT_STAT
    QF_CRIT_ENTRY();
    QF_MEM_SYS();

    // find the pool id that fits the requested event size...
    std::uint_fast8_t poolId = 0U; // zero-based poolId initially
    for (; poolId < priv_.maxPool_; ++poolId) {
        if (evtSize <= QF_EPOOL_EVENT_SIZE_(priv_.ePool_[poolId])) {
            break;
        }
    }

    // precondition:
    // - cannot run out of registered pools
    Q_REQUIRE_INCRIT(300, poolId < priv_.maxPool_);

    ++poolId; // convert to 1-based poolId

    QF_MEM_APP();
    QF_CRIT_EXIT();

    // get event e (port-dependent)...
    QEvt *e;
    #ifdef Q_SPY
    QF_EPOOL_GET_(priv_.ePool_[poolId - 1U], e,
                  ((margin != NO_MARGIN) ? margin : 0U),
                  static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId);
    #else
    QF_EPOOL_GET_(priv_.ePool_[poolId - 1U], e,
                  ((margin != NO_MARGIN) ? margin : 0U), 0U);
    #endif

    if (e != nullptr) { // was e allocated correctly?
        e->sig     = static_cast<QSignal>(sig); // set the signal
        e->refCtr_ = 0U; // initialize the reference counter to 0
        e->evtTag_ = static_cast<std::uint8_t>(QEvt::MARKER | poolId);

        QS_CRIT_ENTRY();
        QS_MEM_SYS();
        QS_BEGIN_PRE_(QS_QF_NEW,
                static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId)
            QS_TIME_PRE_();        // timestamp
            QS_EVS_PRE_(evtSize);  // the size of the event
            QS_SIG_PRE_(sig);      // the signal of the event
        QS_END_PRE_()
        QS_MEM_APP();
        QS_CRIT_EXIT();
    }
    else { // event was not allocated

        QF_CRIT_ENTRY();
        // This assertion means that the event allocation failed,
        // and this failure cannot be tolerated. The most frequent
        // reason is an event leak in the application.
        Q_ASSERT_INCRIT(320, margin != NO_MARGIN);

        QS_MEM_SYS();
        QS_BEGIN_PRE_(QS_QF_NEW_ATTEMPT,
                static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId)
            QS_TIME_PRE_();        // timestamp
            QS_EVS_PRE_(evtSize);  // the size of the event
            QS_SIG_PRE_(sig);      // the signal of the event
        QS_END_PRE_()
        QS_MEM_APP();

        QF_CRIT_EXIT();
    }

    // the returned event e is guaranteed to be valid (not NULL)
    // if we can't tolerate failed allocation
    return e;
}

//${QF::QF-dyn::gc} ..........................................................
void gc(QEvt const * const e) noexcept {
    QF_CRIT_STAT
    QF_CRIT_ENTRY();
    Q_REQUIRE_INCRIT(402, QEvt::verify_(e));

    std::uint_fast8_t const poolId = e->getPoolId_();

    if (poolId != 0U) { // is it a pool event (mutable)?
        QF_MEM_SYS();

        if (e->refCtr_ > 1U) { // isn't this the last reference?

            QS_BEGIN_PRE_(QS_QF_GC_ATTEMPT,
                    static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId)
                QS_TIME_PRE_();       // timestamp
                QS_SIG_PRE_(e->sig);  // the signal of the event
                QS_2U8_PRE_(poolId, e->refCtr_); // poolId & refCtr
            QS_END_PRE_()

            QEvt_refCtr_dec_(e); // decrement the ref counter

            QF_MEM_APP();
            QF_CRIT_EXIT();
        }
        else { // this is the last reference to this event, recycle it

            QS_BEGIN_PRE_(QS_QF_GC,
                    static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId)
                QS_TIME_PRE_();       // timestamp
                QS_SIG_PRE_(e->sig);  // the signal of the event
                QS_2U8_PRE_(poolId, e->refCtr_); // poolId & refCtr
            QS_END_PRE_()

            // pool number must be in range
            Q_ASSERT_INCRIT(410, (poolId <= priv_.maxPool_)
                                  && (poolId <= QF_MAX_EPOOL));
            QF_MEM_APP();
            QF_CRIT_EXIT();

            // NOTE: casting 'const' away is legit because it's a pool event
    #ifdef Q_SPY
            QF_EPOOL_PUT_(priv_.ePool_[poolId - 1U],
                QF_CONST_CAST_(QEvt*, e),
                static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId);
    #else
            QF_EPOOL_PUT_(priv_.ePool_[poolId - 1U],
                QF_CONST_CAST_(QEvt*, e), 0U);
    #endif
        }
    }
    else {
        QF_CRIT_EXIT();
    }
}

//${QF::QF-dyn::newRef_} .....................................................
QEvt const * newRef_(
    QEvt const * const e,
    QEvt const * const evtRef) noexcept
{
    #ifdef Q_UNSAFE
    Q_UNUSED_PAR(evtRef);
    #endif

    QF_CRIT_STAT
    QF_CRIT_ENTRY();

    Q_REQUIRE_INCRIT(502, QEvt::verify_(e));

    std::uint_fast8_t const poolId = e->getPoolId_();

    Q_REQUIRE_INCRIT(500, (poolId != 0U)
        && (evtRef == nullptr));

    QEvt_refCtr_inc_(e); // increments the ref counter

    QS_MEM_SYS();
    QS_BEGIN_PRE_(QS_QF_NEW_REF,
            static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId)
        QS_TIME_PRE_();       // timestamp
        QS_SIG_PRE_(e->sig);  // the signal of the event
        QS_2U8_PRE_(poolId, e->refCtr_); // poolId & refCtr
    QS_END_PRE_()
    QS_MEM_APP();

    QF_CRIT_EXIT();

    return e;
}

//${QF::QF-dyn::deleteRef_} ..................................................
void deleteRef_(QEvt const * const evtRef) noexcept {
    QEvt const * const e = evtRef;

    QF_CRIT_STAT
    QF_CRIT_ENTRY();
    Q_REQUIRE_INCRIT(602, QEvt::verify_(e));

    #ifdef Q_SPY
    std::uint_fast8_t const poolId = e->getPoolId_();
    #endif

    QS_MEM_SYS();
    QS_BEGIN_PRE_(QS_QF_DELETE_REF,
            static_cast<std::uint_fast8_t>(QS_EP_ID) + poolId)
        QS_TIME_PRE_();       // timestamp
        QS_SIG_PRE_(e->sig);  // the signal of the event
        QS_2U8_PRE_(poolId, e->refCtr_); // poolId & refCtr
    QS_END_PRE_()
    QS_MEM_APP();

    QF_CRIT_EXIT();

    #if (QF_MAX_EPOOL > 0U)
    gc(evtRef); // recycle the referenced event
    #endif
}

} // namespace QF
} // namespace QP
//$enddef${QF::QF-dyn} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#endif // (QF_MAX_EPOOL > 0U) mutable events configured