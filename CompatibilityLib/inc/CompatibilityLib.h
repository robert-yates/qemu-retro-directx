#pragma once

#ifdef LOAD_WINE
    #include "config.h"
    #include "wined3d_private.h"
#endif


NTSTATUS WINAPI D3DKMTDestroyDCFromMemory_compat(const D3DKMT_DESTROYDCFROMMEMORY *desc);
NTSTATUS WINAPI D3DKMTCreateDCFromMemory_compat(D3DKMT_CREATEDCFROMMEMORY *desc);
NTSTATUS WINAPI D3DKMTSetVidPnSourceOwner_compat(const D3DKMT_SETVIDPNSOURCEOWNER *desc);
NTSTATUS WINAPI D3DKMTOpenAdapterFromGdiDisplayName_compat(D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME *desc);
NTSTATUS WINAPI D3DKMTDestroyDevice_compat(const D3DKMT_DESTROYDEVICE *desc);
NTSTATUS WINAPI D3DKMTCreateDevice_compat(D3DKMT_CREATEDEVICE *desc);
NTSTATUS WINAPI D3DKMTCloseAdapter_compat(const D3DKMT_CLOSEADAPTER *desc);
NTSTATUS WINAPI D3DKMTOpenAdapterFromLuid_compat(D3DKMT_OPENADAPTERFROMLUID * desc );
void NtDelayExecution_compat(BOOL Alertable, LARGE_INTEGER *DelayInterval);
NTSTATUS NtWaitForSingleObject_compat(HANDLE Handle, BOOL Alertable, PLARGE_INTEGER Timeout);