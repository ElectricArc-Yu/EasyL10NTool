#pragma once

class L10NEnums
{
public:
	
};

UENUM(BlueprintType)
enum class ELanguage : uint8
{
	English UMETA(DisplayName = "English"),
	SimplifiedChinese UMETA(DisplayName = "简体中文 (Simplified Chinese)"),
	TraditionalChinese UMETA(DisplayName = "繁體中文 (Traditional Chinese)"),
	Japanese UMETA(DisplayName = "日本語 (Japanese)"),
	Korean UMETA(DisplayName = "한국어 (Korean)"),
	French UMETA(DisplayName = "Français (French)"),
	German UMETA(DisplayName = "Deutsch (German)"),
	SpanishSpain UMETA(DisplayName = "Español - España (Spanish - Spain)"),
	SpanishLatinAmerica UMETA(DisplayName = "Español - Latinoamérica (Spanish - Latin America)"),
	Italian UMETA(DisplayName = "Italiano (Italian)"),
	Thai UMETA(DisplayName = "ไทย (Thai)"),
	Bulgarian UMETA(DisplayName = "български (Bulgarian)"),
	Czech UMETA(DisplayName = "čeština (Czech)"),
	Danish UMETA(DisplayName = "dansk (Danish)"),
	Greek UMETA(DisplayName = "Ελληνικά (Greek)"),
	BahasaIndonesia UMETA(DisplayName = "Bahasa Indonesia (Indonesian)"),
	Hungarian UMETA(DisplayName = "Magyar (Hungarian)"),
	Dutch UMETA(DisplayName = "Nederlands (Dutch)"),
	Norwegian UMETA(DisplayName = "Norsk (Norwegian)"),
	Polish UMETA(DisplayName = "polski (Polish)"),
	PortugueseBrazil UMETA(DisplayName = "Português - Brasil (Portuguese - Brazil)"),
	PortuguesePortugal UMETA(DisplayName = "Português - Portugal (Portuguese - Portugal)"),
	Romanian UMETA(DisplayName = "română (Romanian)"),
	Russian UMETA(DisplayName = "русский (Russian)"),
	Finnish UMETA(DisplayName = "suomi (Finnish)"),
	Swedish UMETA(DisplayName = "svenska (Swedish)"),
	Turkish UMETA(DisplayName = "Türkçe (Turkish)"),
	Vietnamese UMETA(DisplayName = "Tiếng Việt (Vietnamese)"),
	Ukrainian UMETA(DisplayName = "українська (Ukrainian)"),
};