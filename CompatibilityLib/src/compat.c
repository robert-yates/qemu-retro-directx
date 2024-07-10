#define LOAD_WINE
#include "CompatibilityLib.h"

static LUID* coreLuid = NULL;

NTSTATUS WINAPI D3DKMTDestroyDCFromMemory_compat(const D3DKMT_DESTROYDCFROMMEMORY *desc) {
    MessageBoxA(NULL, "D3DKMTDestroyDCFromMemory", "CompatibilityLib", MB_OK);
    return 0;
}

NTSTATUS WINAPI D3DKMTCreateDCFromMemory_compat(D3DKMT_CREATEDCFROMMEMORY *desc) {
    MessageBoxA(NULL, "D3DKMTCreateDCFromMemory", "CompatibilityLib", MB_OK);
    return 0;
}

NTSTATUS WINAPI D3DKMTSetVidPnSourceOwner_compat(const D3DKMT_SETVIDPNSOURCEOWNER *desc) {
    MessageBoxA(NULL, "D3DKMTSetVidPnSourceOwner", "CompatibilityLib", MB_OK);
    return 0;
}

NTSTATUS WINAPI D3DKMTOpenAdapterFromGdiDisplayName_compat(D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME *desc) {
    
    
    // We should track the display name for unique LUIDs
    // but this is an unlikely use case
    if (coreLuid == NULL) {
        coreLuid = (LUID*)malloc(sizeof(LUID));
        AllocateLocallyUniqueId(coreLuid);
    }

    desc->AdapterLuid.HighPart = coreLuid->HighPart;
    desc->AdapterLuid.LowPart = coreLuid->LowPart;
    desc->hAdapter = 0x1000;
    desc->VidPnSourceId = 1;

    return 0;
}

NTSTATUS WINAPI D3DKMTDestroyDevice_compat(const D3DKMT_DESTROYDEVICE *desc) {
    //MessageBoxA(NULL, "D3DKMTDestroyDevice", "CompatibilityLib", MB_OK);
    return 0;
}

NTSTATUS WINAPI D3DKMTCreateDevice_compat(D3DKMT_CREATEDEVICE *desc) {
    //desc->hDevice = 0x1000;
    return 0;
}

NTSTATUS WINAPI D3DKMTCloseAdapter_compat(const D3DKMT_CLOSEADAPTER *desc) {
    return 0;
}

NTSTATUS WINAPI D3DKMTOpenAdapterFromLuid_compat(D3DKMT_OPENADAPTERFROMLUID * desc ){
    desc->hAdapter = 0x1000;
    return 0;
}

void NtDelayExecution_compat(BOOL Alertable, LARGE_INTEGER *DelayInterval) {
    LONGLONG delayInMilliseconds = -DelayInterval->QuadPart / 10000;

    if (delayInMilliseconds < 0) {
        delayInMilliseconds = 0;
    }

    Sleep((DWORD)delayInMilliseconds);
}


NTSTATUS NtWaitForSingleObject_compat(HANDLE Handle, BOOL Alertable, PLARGE_INTEGER Timeout) {
    DWORD waitResult;
    DWORD timeoutMilliseconds;

    if (Timeout == NULL) {
        timeoutMilliseconds = INFINITE;
    } else {
        LONGLONG timeout100ns = Timeout->QuadPart;
        if (timeout100ns < 0) {
            timeoutMilliseconds = (DWORD)(-timeout100ns / 10000);  // Convert to milliseconds
        } else {
            return STATUS_ALERTED;
        }
    }

    waitResult = WaitForSingleObject(Handle, timeoutMilliseconds);

    switch (waitResult) {
        case WAIT_OBJECT_0:
            return STATUS_SUCCESS;
        case WAIT_TIMEOUT:
            return STATUS_TIMEOUT;
        default:
            return STATUS_ALERTED;
    }
}