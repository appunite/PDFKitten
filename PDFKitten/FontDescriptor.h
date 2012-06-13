#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "FontFile.h"

static const char *kAscentKey = "Ascent";
static const char *kDescentKey = "Descent";
static const char *kLeadingKey = "Leading";
static const char *kCapHeightKey = "CapHeight";
static const char *kXHeightKey = "XHeight";
static const char *kAverageWidthKey = "AvgWidth";
static const char *kMaxWidthKey = "MaxWidth";
static const char *kMissingWidthKey = "MissingWidth";
static const char *kFlagsKey = "Flags";
static const char *kStemVKey = "StemV";
static const char *kStemHKey = "StemH";
static const char *kItalicAngleKey = "ItalicAngle";
static const char *kFontNameKey = "FontName";
static const char *kFontBBoxKey = "FontBBox";
static const char *kFontFileKey = "FontFile";

/* Flags as defined in PDF 1.7 */
typedef enum FontFlags
{
	FontFixedPitch		= 1 << 0,
	FontSerif			= 1 << 1,
	FontSymbolic		= 1 << 2,
	FontScript			= 1 << 3,
	FontNonSymbolic		= 1 << 5,
	FontItalic			= 1 << 6,
	FontAllCap			= 1 << 16,
	FontSmallCap		= 1 << 17,
	FontForceBold		= 1 << 18,
} FontFlags;


@interface FontDescriptor : NSObject {
	CGFloat descent;
	CGFloat ascent;
	CGFloat leading;
	CGFloat capHeight;
	CGFloat xHeight;
	CGFloat averageWidth;
	CGFloat maxWidth;
	CGFloat missingWidth;
	CGFloat verticalStemWidth;
	CGFloat horizontalStemHeigth;
	CGFloat italicAngle;
	CGRect bounds;
	NSUInteger flags;
	NSString *fontName;
	FontFile *fontFile;
}

/* Initialize a descriptor using a FontDescriptor dictionary */
- (id)initWithPDFDictionary:(CGPDFDictionaryRef)dict;

// TODO: temporarily public
+ (void)parseFontFile:(NSData *)data;

@property (nonatomic, assign) CGRect bounds;
@property (nonatomic, assign) CGFloat ascent;
@property (nonatomic, assign) CGFloat descent;
@property (nonatomic, assign) CGFloat leading;
@property (nonatomic, assign) CGFloat capHeight;
@property (nonatomic, assign) CGFloat xHeight;
@property (nonatomic, assign) CGFloat averageWidth;
@property (nonatomic, assign) CGFloat maxWidth;
@property (nonatomic, assign) CGFloat missingWidth;
@property (nonatomic, assign) CGFloat verticalStemWidth;
@property (nonatomic, assign) CGFloat horizontalStemWidth;
@property (nonatomic, assign) CGFloat italicAngle;
@property (nonatomic, assign) NSUInteger flags;
@property (nonatomic, readonly, getter = isSymbolic) BOOL symbolic;
@property (nonatomic, copy) NSString *fontName;
@property (nonatomic, readonly) FontFile *fontFile;
@end
