// Copyright 2014 Citra Emulator Project
// Copyright 2024 Lime3DS Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/apt/apt_u.h"

namespace Service::APT {

APT_U::APT_U(std::shared_ptr<Module> apt)
    : Module::APTInterface(std::move(apt), "APT:U", MaxAPTSessions) {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, &APT_U::GetLockHandle, "GetLockHandle"},
        {0x0002, &APT_U::Initialize, "Initialize"},
        {0x0003, &APT_U::Enable, "Enable"},
        {0x0004, &APT_U::Finalize, "Finalize"},
        {0x0005, &APT_U::GetAppletManInfo, "GetAppletManInfo"},
        {0x0006, &APT_U::GetAppletInfo, "GetAppletInfo"},
        {0x0007, nullptr, "GetLastSignaledAppletId"},
        {0x0008, &APT_U::CountRegisteredApplet, "CountRegisteredApplet"},
        {0x0009, &APT_U::IsRegistered, "IsRegistered"},
        {0x000A, &APT_U::GetAttribute, "GetAttribute"},
        {0x000B, &APT_U::InquireNotification, "InquireNotification"},
        {0x000C, &APT_U::SendParameter, "SendParameter"},
        {0x000D, &APT_U::ReceiveParameter, "ReceiveParameter"},
        {0x000E, &APT_U::GlanceParameter, "GlanceParameter"},
        {0x000F, &APT_U::CancelParameter, "CancelParameter"},
        {0x0010, nullptr, "DebugFunc"},
        {0x0011, nullptr, "MapProgramIdForDebug"},
        {0x0012, nullptr, "SetHomeMenuAppletIdForDebug"},
        {0x0013, nullptr, "GetPreparationState"},
        {0x0014, nullptr, "SetPreparationState"},
        {0x0015, &APT_U::PrepareToStartApplication, "PrepareToStartApplication"},
        {0x0016, &APT_U::PreloadLibraryApplet, "PreloadLibraryApplet"},
        {0x0017, &APT_U::FinishPreloadingLibraryApplet, "FinishPreloadingLibraryApplet"},
        {0x0018, &APT_U::PrepareToStartLibraryApplet, "PrepareToStartLibraryApplet"},
        {0x0019, &APT_U::PrepareToStartSystemApplet, "PrepareToStartSystemApplet"},
        {0x001A, &APT_U::PrepareToStartNewestHomeMenu, "PrepareToStartNewestHomeMenu"},
        {0x001B, &APT_U::StartApplication, "StartApplication"},
        {0x001C, &APT_U::WakeupApplication, "WakeupApplication"},
        {0x001D, &APT_U::CancelApplication, "CancelApplication"},
        {0x001E, &APT_U::StartLibraryApplet, "StartLibraryApplet"},
        {0x001F, &APT_U::StartSystemApplet, "StartSystemApplet"},
        {0x0020, nullptr, "StartNewestHomeMenu"},
        {0x0021, &APT_U::OrderToCloseApplication, "OrderToCloseApplication"},
        {0x0022, &APT_U::PrepareToCloseApplication, "PrepareToCloseApplication"},
        {0x0023, nullptr, "PrepareToJumpToApplication"},
        {0x0024, nullptr, "JumpToApplication"},
        {0x0025, &APT_U::PrepareToCloseLibraryApplet, "PrepareToCloseLibraryApplet"},
        {0x0026, &APT_U::PrepareToCloseSystemApplet, "PrepareToCloseSystemApplet"},
        {0x0027, &APT_U::CloseApplication, "CloseApplication"},
        {0x0028, &APT_U::CloseLibraryApplet, "CloseLibraryApplet"},
        {0x0029, &APT_U::CloseSystemApplet, "CloseSystemApplet"},
        {0x002A, &APT_U::OrderToCloseSystemApplet, "OrderToCloseSystemApplet"},
        {0x002B, &APT_U::PrepareToJumpToHomeMenu, "PrepareToJumpToHomeMenu"},
        {0x002C, &APT_U::JumpToHomeMenu, "JumpToHomeMenu"},
        {0x002D, &APT_U::PrepareToLeaveHomeMenu, "PrepareToLeaveHomeMenu"},
        {0x002E, &APT_U::LeaveHomeMenu, "LeaveHomeMenu"},
        {0x002F, nullptr, "PrepareToLeaveResidentApplet"},
        {0x0030, nullptr, "LeaveResidentApplet"},
        {0x0031, &APT_U::PrepareToDoApplicationJump, "PrepareToDoApplicationJump"},
        {0x0032, &APT_U::DoApplicationJump, "DoApplicationJump"},
        {0x0033, &APT_U::GetProgramIdOnApplicationJump, "GetProgramIdOnApplicationJump"},
        {0x0034, &APT_U::SendDeliverArg, "SendDeliverArg"},
        {0x0035, &APT_U::ReceiveDeliverArg, "ReceiveDeliverArg"},
        {0x0036, &APT_U::LoadSysMenuArg, "LoadSysMenuArg"},
        {0x0037, &APT_U::StoreSysMenuArg, "StoreSysMenuArg"},
        {0x0038, nullptr, "PreloadResidentApplet"},
        {0x0039, nullptr, "PrepareToStartResidentApplet"},
        {0x003A, nullptr, "StartResidentApplet"},
        {0x003B, &APT_U::CancelLibraryApplet, "CancelLibraryApplet"},
        {0x003C, &APT_U::SendDspSleep, "SendDspSleep"},
        {0x003D, &APT_U::SendDspWakeUp, "SendDspWakeUp"},
        {0x003E, &APT_U::ReplySleepQuery, "ReplySleepQuery"},
        {0x003F, &APT_U::ReplySleepNotificationComplete, "ReplySleepNotificationComplete"},
        {0x0040, &APT_U::SendCaptureBufferInfo, "SendCaptureBufferInfo"},
        {0x0041, &APT_U::ReceiveCaptureBufferInfo, "ReceiveCaptureBufferInfo"},
        {0x0042, nullptr, "SleepSystem"},
        {0x0043, &APT_U::NotifyToWait, "NotifyToWait"},
        {0x0044, &APT_U::GetSharedFont, "GetSharedFont"},
        {0x0045, &APT_U::GetWirelessRebootInfo, "GetWirelessRebootInfo"},
        {0x0046, &APT_U::Wrap, "Wrap"},
        {0x0047, &APT_U::Unwrap, "Unwrap"},
        {0x0048, &APT_U::GetProgramInfo, "GetProgramInfo"},
        {0x0049, &APT_U::Reboot, "Reboot"},
        {0x004A, &APT_U::GetCaptureInfo, "GetCaptureInfo"},
        {0x004B, &APT_U::AppletUtility, "AppletUtility"},
        {0x004C, nullptr, "SetFatalErrDispMode"},
        {0x004D, nullptr, "GetAppletProgramInfo"},
        {0x004E, &APT_U::HardwareResetAsync, "HardwareResetAsync"},
        {0x004F, &APT_U::SetAppCpuTimeLimit, "SetAppCpuTimeLimit"},
        {0x0050, &APT_U::GetAppCpuTimeLimit, "GetAppCpuTimeLimit"},
        {0x0051, &APT_U::GetStartupArgument, "GetStartupArgument"},
        {0x0052, nullptr, "Wrap1"},
        {0x0053, nullptr, "Unwrap1"},
        {0x0054, &APT_U::Unknown54, "Unknown54"},
        {0x0055, &APT_U::SetScreenCapturePostPermission, "SetScreenCapturePostPermission"},
        {0x0056, &APT_U::GetScreenCapturePostPermission, "GetScreenCapturePostPermission"},
        {0x0057, &APT_U::WakeupApplication2, "WakeupApplication2"},
        {0x0058, &APT_U::GetProgramId, "GetProgramId"},
        {0x0101, &APT_U::GetTargetPlatform, "GetTargetPlatform"},
        {0x0102, &APT_U::CheckNew3DS, "CheckNew3DS"},
        {0x0103, &APT_U::GetApplicationRunningMode, "GetApplicationRunningMode"},
        {0x0104, &APT_U::IsStandardMemoryLayout, "IsStandardMemoryLayout"},
        {0x0105, &APT_U::IsTitleAllowed, "IsTitleAllowed"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

} // namespace Service::APT

SERIALIZE_EXPORT_IMPL(Service::APT::APT_U)
