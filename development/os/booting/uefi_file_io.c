/*******************************************************************************
* filename: uefi_file_io.c
* C code using UEFI boot services (like in a bootloader)
*******************************************************************************/

/*
 * Below GUIDs are defined in the UEFI specification and usually come from
 * <Protocol/*.h> in EDK2 headers.
 */
//----------------------------------------------------------------<Protocol/*.h>
// Simple File System Protocol
EFI_GUID gEfiSimpleFileSystemProtocolGuid = { 
	{ 0x0964e5b2, 0x6459, 0x11d2},
	{ 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b }};

// Block I/O Protocol
EFI_GUID gEfiBlockIoProtocolGuid = {
	{0x0964e5b21, 0x6459, 0x11d2},
	{0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b }};
//----------------------------------------------------------------<Protocol/*.h>


#include <efi.h>
#include <efilib.h>

// GUIDs must be declared
EFI_GUID gEfiSimpleFileSystemProtocolGuid = { 
	{ 0x0964e5b2, 0x6459, 0x11d2},
	{ 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b }};

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	InitializeLib(ImageHandle, SystemTable);

	EFI_FILE_IO_INTERFACE *IO;
	EFI_FILE_HANDLE Root, File;
	CHAR16 *filename = L"test.dat";
	UINT8 buffer[512];
	UINT size = sizeof(buffer);

	// Locate Simple FileSystem Protocol
	EFI_STATUS status = uefi_call_wrapper(SystemTable->BootServices->LocateProtocol,
			3,
			&gEfiSimpleFileSystemProtocolGuid,
			NULL,
			(void**)&IO);
	
	if (EFI_ERROR(status))
		return status;

	// Open root volume
	status = IO->OpenVolume(IO, &Root);
	if (EFI_ERROR(status))
		return status;

	// Open file
	status = Root->Open(Root, &File, filename, EFI_FILE_MODE_READ, 0);
	if (EFI_ERROR(status))
		return status;

	// Read contents
	status = File->Read(File, &size, buffer);
	if (EFI_ERROR(status))
		return status;

	return EFI_SUCCESS;
}

