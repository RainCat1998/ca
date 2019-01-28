#include "pch.h"
#include <Windows.h>
#include <stdio.h>
#include <process.h>

typedef LONG NTSTATUS;
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)


typedef enum _SYSTEM_INFORMATION_CLASS {
	SystemBasicInformation,              // 0        Y        N
	SystemProcessorInformation,          // 1        Y        N
	SystemPerformanceInformation,        // 2        Y        N
	SystemTimeOfDayInformation,          // 3        Y        N
	SystemNotImplemented1,               // 4        Y        N
	SystemProcessesAndThreadsInformation, // 5       Y        N
	SystemCallCounts,                    // 6        Y        N
	SystemConfigurationInformation,      // 7        Y        N
	SystemProcessorTimes,                // 8        Y        N
	SystemGlobalFlag,                    // 9        Y        Y
	SystemNotImplemented2,               // 10       Y        N
	SystemModuleInformation,             // 11       Y        N
	SystemLockInformation,               // 12       Y        N
	SystemNotImplemented3,               // 13       Y        N
	SystemNotImplemented4,               // 14       Y        N
	SystemNotImplemented5,               // 15       Y        N
	SystemHandleInformation,             // 16       Y        N
	SystemObjectInformation,             // 17       Y        N
	SystemPagefileInformation,           // 18       Y        N
	SystemInstructionEmulationCounts,    // 19       Y        N
	SystemInvalidInfoClass1,             // 20
	SystemCacheInformation,              // 21       Y        Y
	SystemPoolTagInformation,            // 22       Y        N
	SystemProcessorStatistics,           // 23       Y        N
	SystemDpcInformation,                // 24       Y        Y
	SystemNotImplemented6,               // 25       Y        N
	SystemLoadImage,                     // 26       N        Y
	SystemUnloadImage,                   // 27       N        Y
	SystemTimeAdjustment,                // 28       Y        Y
	SystemNotImplemented7,               // 29       Y        N
	SystemNotImplemented8,               // 30       Y        N
	SystemNotImplemented9,               // 31       Y        N
	SystemCrashDumpInformation,          // 32       Y        N
	SystemExceptionInformation,          // 33       Y        N
	SystemCrashDumpStateInformation,     // 34       Y        Y/N
	SystemKernelDebuggerInformation,     // 35       Y        N
	SystemContextSwitchInformation,      // 36       Y        N
	SystemRegistryQuotaInformation,      // 37       Y        Y
	SystemLoadAndCallImage,              // 38       N        Y
	SystemPrioritySeparation,            // 39       N        Y
	SystemNotImplemented10,              // 40       Y        N
	SystemNotImplemented11,              // 41       Y        N
	SystemInvalidInfoClass2,             // 42
	SystemInvalidInfoClass3,             // 43
	SystemTimeZoneInformation,           // 44       Y        N
	SystemLookasideInformation,          // 45       Y        N
	SystemSetTimeSlipEvent,              // 46       N        Y
	SystemCreateSession,                 // 47       N        Y
	SystemDeleteSession,                 // 48       N        Y
	SystemInvalidInfoClass4,             // 49
	SystemRangeStartInformation,         // 50       Y        N
	SystemVerifierInformation,           // 51       Y        Y
	SystemAddVerifier,                   // 52       N        Y
	SystemSessionProcessesInformation    // 53       Y        N
} SYSTEM_INFORMATION_CLASS;

typedef struct
{
	USHORT Length;
	USHORT MaxLen;
	USHORT *Buffer;
}UNICODE_STRING, *PUNICODE_STRING;

typedef enum _OBJECT_INFORMATION_CLASS {
	ObjectBasicInformation,
	ObjectNameInformation,
	ObjectTypeInformation,
	ObjectAllInformation,
	ObjectDataInformation
} OBJECT_INFORMATION_CLASS;

typedef struct _OBJECT_NAME_INFORMATION {
	UNICODE_STRING Name;
} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;



typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO {
	ULONG ProcessId;
	UCHAR ObjectTypeNumber;
	UCHAR Flags;
	USHORT Handle;
	PVOID Object;
	ACCESS_MASK GrantedAccess;
} SYSTEM_HANDLE_TABLE_ENTRY_INFO, *PSYSTEM_HANDLE_TABLE_ENTRY_INFO;

typedef struct _SYSTEM_HANDLE_INFORMATIONS {
	ULONG NumberOfHandles;
	SYSTEM_HANDLE_TABLE_ENTRY_INFO Handles[1];
} SYSTEM_HANDLE_INFORMATIONS, *PSYSTEM_HANDLE_INFORMATIONS;

typedef struct _OBJECT_BASIC_INFORMATION {
	ULONG                   Attributes;
	ACCESS_MASK             DesiredAccess;
	ULONG                   HandleCount;
	ULONG                   ReferenceCount;
	ULONG                   PagedPoolUsage;
	ULONG                   NonPagedPoolUsage;
	ULONG                   Reserved[3];
	ULONG                   NameInformationLength;
	ULONG                   TypeInformationLength;
	ULONG                   SecurityDescriptorLength;
	LARGE_INTEGER           CreationTime;
} OBJECT_BASIC_INFORMATION, *POBJECT_BASIC_INFORMATION;

typedef enum _PROCESSINFOCLASS
{
	ProcessBasicInformation = 0, // 0, q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
	ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
	ProcessIoCounters, // q: IO_COUNTERS
	ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX
	ProcessTimes, // q: KERNEL_USER_TIMES
	ProcessBasePriority, // s: KPRIORITY
	ProcessRaisePriority, // s: ULONG
	ProcessDebugPort, // q: HANDLE
	ProcessExceptionPort, // s: HANDLE
	ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
	ProcessLdtInformation, // 10
	ProcessLdtSize,
	ProcessDefaultHardErrorMode, // qs: ULONG
	ProcessIoPortHandlers, // (kernel-mode only)
	ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
	ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
	ProcessUserModeIOPL,
	ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
	ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
	ProcessWx86Information,
	ProcessHandleCount, // 20, q: ULONG, PROCESS_HANDLE_INFORMATION
	ProcessAffinityMask, // s: KAFFINITY
	ProcessPriorityBoost, // qs: ULONG
	ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
	ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
	ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
	ProcessWow64Information, // q: ULONG_PTR
	ProcessImageFileName, // q: UNICODE_STRING
	ProcessLUIDDeviceMapsEnabled, // q: ULONG
	ProcessBreakOnTermination, // qs: ULONG
	ProcessDebugObjectHandle, // 30, q: HANDLE
	ProcessDebugFlags, // qs: ULONG
	ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
	ProcessIoPriority, // qs: ULONG
	ProcessExecuteFlags, // qs: ULONG
	ProcessResourceManagement,
	ProcessCookie, // q: ULONG
	ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
	ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION
	ProcessPagePriority, // q: ULONG
	ProcessInstrumentationCallback, // 40
	ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
	ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
	ProcessImageFileNameWin32, // q: UNICODE_STRING
	ProcessImageFileMapping, // q: HANDLE (input)
	ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
	ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
	ProcessGroupInformation, // q: USHORT[]
	ProcessTokenVirtualizationEnabled, // s: ULONG
	ProcessConsoleHostProcess, // q: ULONG_PTR
	ProcessWindowInformation, // 50, q: PROCESS_WINDOW_INFORMATION
	ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
	ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
	ProcessDynamicFunctionTableInformation,
	ProcessHandleCheckingMode,
	ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
	ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
	MaxProcessInfoClass
}PROCESSINFOCLASS;

typedef struct _OBJECT_TYPE_INFORMATION
{
	UNICODE_STRING TypeName;
	ULONG TotalNumberOfObjects;
	ULONG TotalNumberOfHandles;
	ULONG TotalPagedPoolUsage;
	ULONG TotalNonPagedPoolUsage;
	ULONG TotalNamePoolUsage;
	ULONG TotalHandleTableUsage;
	ULONG HighWaterNumberOfObjects;
	ULONG HighWaterNumberOfHandles;
	ULONG HighWaterPagedPoolUsage;
	ULONG HighWaterNonPagedPoolUsage;
	ULONG HighWaterNamePoolUsage;
	ULONG HighWaterHandleTableUsage;
	ULONG InvalidAttributes;
	GENERIC_MAPPING GenericMapping;
	ULONG ValidAccessMask;
	BOOLEAN SecurityRequired;
	BOOLEAN MaintainHandleCount;
	ULONG PoolType;
	ULONG DefaultPagedPoolCharge;
	ULONG DefaultNonPagedPoolCharge;
} OBJECT_TYPE_INFORMATION, *POBJECT_TYPE_INFORMATION;

typedef NTSTATUS
(NTAPI *ZWQUERYSYSTEMINFORMATION)(
	IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
	OUT PVOID SystemInformation,
	IN ULONG SystemInformationLength,
	OUT PULONG ReturnLength OPTIONAL
	);
typedef NTSTATUS
(WINAPI *ZWQUERYOBJECT)(
	IN HANDLE OPTIONAL,
	IN OBJECT_INFORMATION_CLASS,
	OUT PVOID OPTIONAL,
	IN ULONG,
	OUT PULONG OPTIONAL);

//这个没有用到 不过留着 后面会用到的
typedef NTSTATUS
(WINAPI *ZWQUERYINFORMATIONPROCESS)(
	HANDLE  ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID  ProcessInformation,
	ULONG  ProcessInformationLength,
	PULONG ReturnLength);

typedef long(*RTLADJUSTPRIVILEGE)(ULONG, ULONG, ULONG, PVOID);
RTLADJUSTPRIVILEGE RtlAdjustPrivilege;

//g_
HANDLE g_Event = 0, hTest = 0;
POBJECT_NAME_INFORMATION ObjName;
BOOL g_ZwFaild = FALSE;
ZWQUERYOBJECT ZwQueryObject;
ZWQUERYSYSTEMINFORMATION ZwQuerySystemInformation;

UINT WINAPI ZwThreadProc(PVOID lpParma)
{
	NTSTATUS ntStatus = ZwQueryObject(hTest, ObjectNameInformation, ObjName, 0x512, NULL);//可能锁死
	if (!NT_SUCCESS(ntStatus))
	{
		g_ZwFaild = TRUE;
	}
	SetEvent(g_Event);
	return 0;
}


BOOL ThreadEnumHandleByZwQuerySystemInformation(DWORD pid)
{
	ULONG i;
	ULONG ulSize;
	ULONG* pHandleInfor;
	NTSTATUS ntStatus;
	HMODULE hHanlde;
	PSYSTEM_HANDLE_INFORMATIONS lpHandles;
	POBJECT_BASIC_INFORMATION lpHandleBasic;
	HANDLE hProcess = 0, hThread = 0;
	ULONG errorCode = 0;
	ULONG Count = 0;
	POBJECT_TYPE_INFORMATION TypeInfo;
	UINT dwThread = 0;
	//初始化变量
	ulSize = 0x4000;
	pHandleInfor = NULL;
	ZwQueryObject = NULL;
	ZwQuerySystemInformation = NULL;

	hTest = 0;
	//由于ZwQueryObject和ZwQuerySystemInformation是未导出的函数，需要动态加载Ntdll,dll，然后通过函数GetProcAddress
	//得到它们的函数地址，由于这个dll一般的进程都会在创建的时候加载，所以省略加载，直接获取其模块地址
	hHanlde = GetModuleHandle(L"ntdll.dll");
	if (NULL == hHanlde)
	{
		//加载Ntdll.dll失败
		return FALSE;
	}

	//获取ZwQuerySystemInformation函数地址  
	ZwQuerySystemInformation = (ZWQUERYSYSTEMINFORMATION)GetProcAddress(hHanlde, "ZwQuerySystemInformation");
	if (NULL == ZwQuerySystemInformation)
	{
		//获取ZwQuerySystemInformation函数地址失败
		return FALSE;
	}

	//获取ZwQueryObject函数地址
	ZwQueryObject = (ZWQUERYOBJECT)GetProcAddress(hHanlde, "ZwQueryObject");
	if (NULL == ZwQueryObject)
	{
		//获取ZwQueryObject函数地址失败
		return FALSE;
	}

	//打开进程 复制句柄时用到
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_DUP_HANDLE, FALSE, pid);

	if (hProcess == NULL)
	{
		return FALSE;
	}
	//获取系统所有句柄信息
	do
	{
		//申请内存
		pHandleInfor = (ULONG*)malloc(ulSize);
		if (NULL == pHandleInfor)
		{
			//申请内存失败
			CloseHandle(hProcess);
			return FALSE;
		}

		ntStatus = ZwQuerySystemInformation(SystemHandleInformation, pHandleInfor, ulSize, NULL);
		if (!NT_SUCCESS(ntStatus))
		{
			//空间不足继续申请。
			free(pHandleInfor);
			ulSize = ulSize * 2;
			//为防止ZwQuerySystemInformation一直失败，程序陷入死循环，当申请的空间超过64M时则返回失败
			if (ulSize > 0x4000000)
			{
				CloseHandle(hProcess);
				return FALSE;
			}
		}
	} while (!NT_SUCCESS(ntStatus));
	//转换数据结构类型
	lpHandles = (PSYSTEM_HANDLE_INFORMATIONS)pHandleInfor;
	if (NULL == lpHandles)
	{
		CloseHandle(hProcess);
		return FALSE;
	}
	//申请空间，用于存储对象的名字信息和对象类型名字
	ObjName = (POBJECT_NAME_INFORMATION)malloc(0x512);
	TypeInfo = (POBJECT_TYPE_INFORMATION)malloc(0x512);
	lpHandleBasic = (POBJECT_BASIC_INFORMATION)malloc(sizeof(OBJECT_BASIC_INFORMATION));
	//开始搜索获取的句柄信息，并对句柄对应的对象名进行比较，如果与要求关闭的名字相同，则关闭此句柄
	  //printf("%d\n",lpHandles->NumberOfHandles);
	for (i = 0; i < lpHandles->NumberOfHandles; i++)
	{
		if (pid != lpHandles->Handles[i].ProcessId)
		{
			//printf("%d\n",lpHandles->Handles[i].ProcessId);
			continue;
		}

		if (DuplicateHandle(hProcess, (HANDLE)lpHandles->Handles[i].Handle, GetCurrentProcess(), &hTest, 0, FALSE, DUPLICATE_SAME_ACCESS))
		{
			Count++;
			//获取这个对象的类型名
			ntStatus = ZwQueryObject(hTest, ObjectTypeInformation, TypeInfo, 0x512, NULL);
			if (!NT_SUCCESS(ntStatus))
			{
				//查询失败
				continue;
			}
			ntStatus = ZwQueryObject(hTest, ObjectBasicInformation, lpHandleBasic, sizeof(OBJECT_BASIC_INFORMATION), NULL);
			if (!NT_SUCCESS(ntStatus))
			{
				//查询失败
				continue;
			}
			//获取这个对象的名字信息
			_beginthreadex(NULL, 0, ZwThreadProc, NULL, 0, &dwThread);
			DWORD dwSatu = WaitForSingleObject(g_Event, 500);
			if (dwSatu == WAIT_TIMEOUT) {
				//printf("ObjceTypeName:FILE---ObjectTypeIndex:%d---HandleAttributes:%x---Handle:0x%x---Object:%p\n---HandleName:Device\\NamePapi\n", lpHandles->Handles[i].ObjectTypeNumber, lpHandles->Handles[i].Flags, lpHandles->Handles[i].Handle, lpHandles->Handles[i].Object);
				hThread = OpenThread(THREAD_TERMINATE, FALSE, dwThread);
				if (!TerminateThread(hThread, 0)) {
					CloseHandle(hThread);
					ExitProcess(0);
				}
				CloseHandle(hThread);
				continue;
			}
			if (g_ZwFaild)
			{
				g_ZwFaild = FALSE;
				continue;
			}
			//char pName[1024] = {0};
			////将unicode 字串转换为 ansi字串
			//WideCharToMultiByte(CP_ACP, 0, (LPWCH)ObjName->Name.Buffer, -1, pName, 200, NULL, NULL);
			//if( 0 == strstr(pName, "\\Device\\HarddiskVolume5\\CheatAssistant\\x64\\Release"))
			//{
			//  //找到对应名字的对象，将其关闭
			//	wprintf(L"HandleName:%wZ\n", ObjName->Name);
			//   CloseHandle((HANDLE)lpHandles->Handles[i].Handle);
			//}
			//wprintf(L"ObjName->Name->:%wZ\n", ObjName->Name);
			if (wcsstr((wchar_t *)ObjName, L"\\Device\\HarddiskVolume") && !wcsstr((wchar_t *)ObjName, L"Windows"))
			{
				//wprintf(L"--------------- %wZ   %wZ\n", TypeInfo->TypeName, ObjName->Name);
				//找到对应名字的对象，将其关闭
				wprintf(L"HandleName:%wZ\n", ObjName->Name);
				//CloseHandle((HANDLE)lpHandles->Handles[i].Handle);
				return TRUE;
			}
			//printf("ObjceTypeName:%wZ---ObjectTypeIndex:%d---HandleAttributes:%x---Handle:0x%x---Object:%p\n", TypeInfo->TypeName, lpHandles->Handles[i].ObjectTypeNumber, lpHandles->Handles[i].Flags, lpHandles->Handles[i].Handle, lpHandles->Handles[i].Object);
			//wprintf(L"HandleName:%wZ\n", ObjName->Name);
			//printf("\nRedeferCount:%d\n", lpHandleBasic->ReferenceCount);

		}
		else
		{
			errorCode = GetLastError();
			if (errorCode == 0x32)//不支持读写的句柄 Etw
			{
				//printf("ObjectTypeIndex:0x27---HandleAttributes:000000---Handle:0x%x---Object:%p\n", lpHandles->Handles[i].Handle, lpHandles->Handles[i].Object);
				Count++;
			}
		}
	}

	//释放申请的空间
	free(lpHandles);
	free(ObjName);
	free(TypeInfo);
	free(lpHandleBasic);
	CloseHandle(hProcess);

	printf("Pid:%d----HandleCount:%d\n", pid, Count);
	return TRUE;
}

int main()
{
	//ThreadEnumHandleByZwQuerySystemInformation(GetCurrentProcessId());
	getchar();
}

