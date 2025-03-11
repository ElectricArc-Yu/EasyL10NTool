// Copyright YuChenhaoran,  All Rights Reserved. publish in 2025

#pragma once

#include "Engine/DataTable.h"
#include "L10NStructs.generated.h"

class L10NStructs
{
};

USTRUCT(BlueprintType)
struct FL10NPlainTextTable : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText English;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText SimplifiedChinese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText TraditionalChinese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Japanese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Korean;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText French;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText German;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText SpanishSpain;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText SpanishLatinAmerica;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Italian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Thai;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Bulgarian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Czech;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Danish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Greek;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText BahasaIndonesia;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Hungarian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Dutch;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Norwegian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Polish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText PortugueseBrazil;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText PortuguesePortugal;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Romanian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Russian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Finnish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Swedish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Turkish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Vietnamese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta=(MultiLine = true))
	FText Ukrainian;
};

USTRUCT(BlueprintType)
struct FL10NAssetsTable : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath English;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath SimplifiedChinese;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath TraditionalChinese;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Japanese;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Korean;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath French;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath German;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath SpanishSpain;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath SpanishLatinAmerica;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Italian;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Thai;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Bulgarian;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Czech;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Danish;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Greek;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath BahasaIndonesia;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Hungarian;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Dutch;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Norwegian;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Polish;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath PortugueseBrazil;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath PortuguesePortugal;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Romanian;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Russian;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Finnish;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Swedish;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Turkish;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Vietnamese;
	UPROPERTY(EditAnywhere, Category = "L10N")
	;
	FSoftObjectPath Ukrainian;
};
