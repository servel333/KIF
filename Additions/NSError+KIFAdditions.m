//  Created by Nathan Perry.
//


#import "NSError+KIFAdditions.h"

#import "KIFDefaults.h"


NSString *const KIFErrorDomain = @"KIF";


@implementation NSError (KIFAdditions)


+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  description:(NSString *)description;
{
    NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:description, NSLocalizedDescriptionKey, nil];
    NSError *error = [NSError  errorWithDomain:KIFErrorDomain  code:result  userInfo:userInfo];
    
    return error;
}


+ (NSError *)kifErrorWithDescription:(NSString *)description;
{
    return [self  kifErrorWithResult:KIFTestStepResultFailure  description:description];
}


+ (NSError *)kifErrorWithUnderlyingError:(NSError *)underlyingError  result:(KIFTestStepResult)result  description:(NSString *)description;
{
    NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:underlyingError, NSUnderlyingErrorKey, description, NSLocalizedDescriptionKey, nil];
    NSError *error = [NSError  errorWithDomain:KIFErrorDomain  code:result  userInfo:userInfo];
    
    return error;
}


+ (NSError *)kifErrorWithUnderlyingError:(NSError *)underlyingError  description:(NSString *)description;
{
    return [self  kifErrorWithUnderlyingError:underlyingError  result:KIFTestStepResultFailure  description:description];
}


+ (BOOL)setKifError:(NSError **)error  result:(KIFTestStepResult)result  description:(NSString *)description;
{
    if (error) {
        *error = [self  kifErrorWithResult:result  description:description];
        return YES;
    }
    
    return NO;
}


+ (BOOL)setKifError:(NSError **)error  description:(NSString *)description;
{
    return [self  setKifError:error  result:KIFTestStepResultFailure  description:description];
}


+ (BOOL)setKifError:(NSError **)error  fromStepThrewException:(id)exception;
{
    return [self  setKifError:error  result:KIFTestStepResultFailure  description:[NSString  stringWithFormat:@"Step threw exception: %@", exception]];
}


@end
