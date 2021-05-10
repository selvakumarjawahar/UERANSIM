//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "ctl_task.hpp"

namespace nr::ue
{

RlsControlTask::RlsControlTask(TaskBase *base) : m_udpTask{}
{
    m_logger = base->logBase->makeUniqueLogger(base->config->getLoggerPrefix() + "rls-ctl");
}

void RlsControlTask::initialize(RlsUdpTask *udpTask)
{
    m_udpTask = udpTask;
}

void RlsControlTask::onStart()
{
}

void RlsControlTask::onLoop()
{
    NtsMessage *msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    case NtsMessageType::UE_RLS_TO_RLS: {
        auto *w = dynamic_cast<NwUeRlsToRls *>(msg);
        switch (w->present)
        {
        case NwUeRlsToRls::SIGNAL_CHANGED:
            // TODO
            break;
        case NwUeRlsToRls::RECEIVE_RLS_MESSAGE:
            // TODO
            break;
        default:
            m_logger->unhandledNts(msg);
            break;
        }
        break;
    }
    default:
        m_logger->unhandledNts(msg);
        break;
    }

    delete msg;
}

void RlsControlTask::onQuit()
{
}

} // namespace nr::ue
