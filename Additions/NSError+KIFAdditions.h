//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>

#import "KIFTestStep.h"


@interface NSError (KIFAdditions)


/*!
 @method  kifErrorWithResult:description:
 @abstract  Creates and initializes an NSError object for the KIF domain with the given arguments.
 @param  result  The result to store in the errors 'code' property.
 @param  description  The description of the error.
 */
+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  description:(NSString *)description;


/*!
 @method  kifErrorWithResult:descriptionFormat:formatArgs:
 @abstract  Creates and initializes an NSError object for the KIF domain with the given arguments.
 @param  result  The result to store in the errors 'code' property.
 @param  format  A format string passed directly to NSString. See “Formatting String Objects” for examples of how to use this method, and “String Format Specifiers” for a list of format specifiers. This value must not be nil.
 @param  argList  A list of arguments to substitute into format passed directly to NSString.
 */
+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format  formatArgs:(va_list)argList;


/*!
 @method  kifErrorWithResult:descriptionFormat:
 @abstract  Creates and initializes an NSError object for the KIF domain with the given arguments.
 @param  result  The result to store in the errors 'code' property.
 @param  format  A format string passed directly to NSString. See “Formatting String Objects” for examples of how to use this method, and “String Format Specifiers” for a list of format specifiers. This value must not be nil.
 @param  ...  A comma-separated list of arguments to substitute into format passed directly to NSString.
 */
+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format, ...;


/*!
 @method  setKifError:withResult:description:
 @abstract  Sets the given error if it points to valid memory with the given arguments.
 @param  error  The NSError object to set.
 @param  result  The result to store in the errors 'code' property.
 @param  description  The description of the error.
 @result  Returns a value indicating if the error was actually set.
 */
+ (BOOL)setKifError:(NSError **)error  withResult:(KIFTestStepResult)result  description:(NSString *)description;


/*!
 @method  setKifError:withResult:description:
 @abstract  Sets the given error if it points to valid memory with the given arguments.
 @param  error  The NSError object to set.
 @param  result  The result to store in the errors 'code' property.
 @param  format  A format string passed directly to NSString. See “Formatting String Objects” for examples of how to use this method, and “String Format Specifiers” for a list of format specifiers. This value must not be nil.
 @param  argList  A list of arguments to substitute into format passed directly to NSString.
 @result  Returns a value indicating if the error was actually set.
 */
+ (BOOL)setKifError:(NSError **)error  withResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format  formatArgs:(va_list)argList;


/*!
 @method  setKifError:withResult:description:
 @abstract  Sets the given error if it points to valid memory with the given arguments.
 @param  error  The NSError object to set.
 @param  result  The result to store in the errors 'code' property.
 @param  format  A format string passed directly to NSString. See “Formatting String Objects” for examples of how to use this method, and “String Format Specifiers” for a list of format specifiers. This value must not be nil.
 @param  ...  A comma-separated list of arguments to substitute into format passed directly to NSString.
 @result  Returns a value indicating if the error was actually set.
 */
+ (BOOL)setKifError:(NSError **)error  withResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format, ...;


@end
