#pragma once

#include "Engine/DataTable.h"
#include "L10NStructs.generated.h"

class L10NStructs 
{
public:
	
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
struct FL10NArtTable : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath English;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath SimplifiedChinese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath TraditionalChinese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Japanese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Korean;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath French;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath German;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath SpanishSpain;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath SpanishLatinAmerica;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Italian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Thai;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Bulgarian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Czech;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Danish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Greek;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath BahasaIndonesia;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Hungarian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Dutch;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Norwegian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Polish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath PortugueseBrazil;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath PortuguesePortugal;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Romanian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Russian;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Finnish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Swedish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Turkish;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Vietnamese;
	UPROPERTY(EditAnywhere, Category = "L10N", meta = (AllowedClass = "Texture2D"));
	FSoftObjectPath Ukrainian;
};