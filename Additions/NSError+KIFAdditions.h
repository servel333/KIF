//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>

#import "KIFTestStepResult.h"


/**
 @const  KIFErrorDomain
 @abstract  The error domain string used by KIF.
 @discussion  This is used in places like [NSError initWithDomain:KIFErrorDomain ...
 */
extern NSString *const KIFErrorDomain;


@interface NSError (KIFAdditions)


/**
 @method  kifErrorWithResult:description:
 @abstract  Creates and initializes an NSError object for the KIF domain with the given arguments.
 @param  result  The result to store in the errors 'code' property.
 @param  description  The description of the error.
 */
+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  description:(NSString *)description;


/**
 @method  kifErrorWithResult:description:
 @abstract  Creates and initializes an NSError object for the KIF domain with the given arguments.
 @param  description  The description of the error.
 */
+ (NSError *)kifErrorWithDescription:(NSString *)description;


/**
 @method  kifErrorWithUnderlyingError:result:description:
 @abstract  Creates and initializes an NSError object for the KIF domain with the given arguments.
 @param  underlyingError  The underlying error to put in the new errors user info dictionary.
 @param  result  The result to store in the errors 'code' property.
 @param  description  The description of the error.
 */
+ (NSError *)kifErrorWithUnderlyingError:(NSError *)underlyingError  result:(KIFTestStepResult)result  description:(NSString *)description;


/**
 @method  kifErrorWithUnderlyingError:result:description:
 @abstract  Creates and initializes an NSError object for the KIF domain with the given arguments.
 @param  underlyingError  The underlying error to put in the new errors user info dictionary.
 @param  description  The description of the error.
 */
+ (NSError *)kifErrorWithUnderlyingError:(NSError *)underlyingError  description:(NSString *)description;


/**
 @method  setKifError:withResult:description:
 @abstract  Sets the given error if it points to valid memory with the given arguments.
 @param  error  The NSError pointer to set.
 @param  result  The result to store in the errors 'code' property.
 @param  description  The description of the error.
 @result  Returns a value indicating if the error was actually set.
 */
+ (BOOL)setKifError:(NSError **)error  result:(KIFTestStepResult)result  description:(NSString *)description;


/**
 @method  setKifError:withResult:description:
 @abstract  Sets the given error if it points to valid memory with the given arguments.
 @param  error  The NSError pointer to set.
 @param  description  The description of the error.
 @result  Returns a value indicating if the error was actually set.
 */
+ (BOOL)setKifError:(NSError **)error  description:(NSString *)description;


/**
 @method  setKifError:fromStepThrewException:
 @abstract  Sets the given error if it points to valid memory with the given arguments.
 @param  error  the NSError pointer to set.
 @param  exception  The exception object to include in this NSError as the description.
 @result  Returns a value indicating if the error was actually set.
 */
+ (BOOL)setKifError:(NSError **)error  fromStepThrewException:(id)exception;


@end
