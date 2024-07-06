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