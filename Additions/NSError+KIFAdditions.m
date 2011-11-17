//  Created by Nathan Perry.
//


#import "NSError+KIFAdditions.h"

#import "KIFDefaults.h"


@implementation NSError (KIFAdditions)


+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  description:(NSString *)description;
{
    NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:description, NSLocalizedDescriptionKey, nil];
    NSError * error = [NSError  errorWithDomain:KIF_DOMAIN  code:result  userInfo:userInfo];
    
    return error;
}


+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format  formatArgs:(va_list)argList;
{
    NSString * description = [[[NSString  alloc]  initWithFormat:format  arguments:argList]  autorelease];
    
    return [self kifErrorWithResult:result  description:description];
}


+ (NSError *)kifErrorWithResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format, ...;
{
    va_list args;
    va_start(args, format);
    NSError *error = [self  kifErrorWithResult:result descriptionFormat:format formatArgs:args];
    va_end(args);
    
    return error;
}


+ (BOOL)setKifError:(NSError **)error  withResult:(KIFTestStepResult)result  description:(NSString *)description;
{
    if (error) {
        *error = [self kifErrorWithResult:result description:description];
        return YES;
    }
    
    return NO;
}


+ (BOOL)setKifError:(NSError **)error  withResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format  formatArgs:(va_list)argList;
{
    if (error) {
        *error = [self kifErrorWithResult:result descriptionFormat:format  formatArgs:argList];
        return YES;
    }
    
    return NO;
}


+ (BOOL)setKifError:(NSError **)error  withResult:(KIFTestStepResult)result  descriptionFormat:(NSString *)format, ...;
{
    if (error) {
        va_list args;
        va_start(args, format);
        *error = [self  kifErrorWithResult:result descriptionFormat:format formatArgs:args];
        va_end(args);
        return YES;
    }
    
    return NO;
}


@end
