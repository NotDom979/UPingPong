// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePingPong_init() {}
	PINGPONG_API UFunction* Z_Construct_UDelegateFunction_PingPong_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_PingPong;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_PingPong()
	{
		if (!Z_Registration_Info_UPackage__Script_PingPong.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_PingPong_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/PingPong",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x4E8509CD,
				0xAFD1112D,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_PingPong.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_PingPong.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_PingPong(Z_Construct_UPackage__Script_PingPong, TEXT("/Script/PingPong"), Z_Registration_Info_UPackage__Script_PingPong, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4E8509CD, 0xAFD1112D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
