//  Created by Nathan Perry.
//


#import "KIFStep.h"

#import "KIF.h"
#import "KIFMutableContext.h"


#pragma mark -


@interface KIFStep ()


+ (BOOL)performShouldRunStepIfAvailable:(KIFStepProtocol *)step
                            withContext:(KIFContext *)context;


+ (BOOL)performStepWillBeginIfAvailable:(KIFStepProtocol *)step
                            withContext:(KIFContext *)context;


+ (BOOL)performRunStepIfAvailable:(KIFStepProtocol *)step
                      withContext:(KIFContext *)context;


+ (void)performStepWillTerminateIfAvailable:(KIFStepProtocol *)step
                                withContext:(KIFContext *)context;


@end


#pragma mark -


@implementation KIFStep


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


#pragma mark Running the step


+ (BOOL)runStep:(KIFStepProtocol *)step
   fromScenario:(KIFScenario *)scenario
 withController:(KIFController *)controller
{
    BOOL success = YES;
    KIFMutableContext *context = [KIFMutableContext  context];
    
    [context  setController:controller];
    [context  setScenario:scenario];
    [context  setStep:step];
    [context  setFirstRunStep:[[NSDate  date]  timeIntervalSinceReferenceDate]];
    [context  setLastRunStep:[[NSDate  date]  timeIntervalSinceReferenceDate]];
    context.runStepAgain = NO;
    context.error = nil;
    
    success = [self  runStep:step withContext:context];
    
    if (context.runStepAgain) {
        // FIXME: Run the step again if no errors.
    }
    
    if (context.error) {
        // FIXME: Write context.error to the log
    }
    
    [context release];
    return success;
}


+ (BOOL)runStep:(KIFStepProtocol *)step
    withContext:(KIFContext *)context
{
    BOOL success = YES;
    
    if (![self  performShouldRunStepIfAvailable:step  withContext:context]) {
        
        success = NO;
        
        [self performStepWillTerminateIfAvailable:step  withContext:context];
        
        // Run stepWillTerminate, clean up and go to the next step.
        
    }
    
    if (![self  performStepWillBeginIfAvailable:step  withContext:context]) {
        
        success = NO;
        [self performStepWillTerminateIfAvailable:step  withContext:context];
        
        // Run stepWillTerminate, clean up and fail the scenario.
        
    }
    
    if (![self  performRunStepIfAvailable:step  withContext:context]) {
        
        success = NO;
        [self performStepWillTerminateIfAvailable:step  withContext:context];
        
        // Run stepWillTerminate, clean up and fail the scenario.
        
    }
    
    if (success && context.runStepAgain) {
        
        [self  runStep:step  withContext:context];
        
    } else {
        
        [self performStepWillTerminateIfAvailable:step  withContext:context];
        
    }

    return success;
}


+ (BOOL)performShouldRunStepIfAvailable:(KIFStepProtocol *)step
          withContext:(KIFContext *)context
{
    if ([step  respondsToSelector:@selector(shouldRunStep:)]) {
        return [step  shouldRunStep:context];
    }
    
    return YES;
}


+ (BOOL)performStepWillBeginIfAvailable:(KIFStepProtocol *)step
          withContext:(KIFContext *)context
{
    BOOL result = YES;
    
    if ([step  respondsToSelector:@selector(stepWillBegin:)]) {
        
        @try {
            result = [step  stepWillBegin:context];
        }
        @catch (id exception) {
            
            NSString *errorDescription = [NSString stringWithFormat:@"Step threw exception: %@", exception];
            NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:errorDescription, NSLocalizedDescriptionKey, nil];
            context.error =         [NSError errorWithDomain:KIF_ERROR_DOMAIN  code:KIFTestStepResultFailure userInfo:userInfo];
            context.error = [[[NSError alloc] initWithDomain:KIF_ERROR_DOMAIN  code:KIFTestStepResultFailure userInfo:userInfo] autorelease];
        }
        
    }
    
    return YES;
}


+ (BOOL)performRunStepIfAvailable:(KIFStepProtocol *)step
    withContext:(KIFContext *)context
{
    if ([step  respondsToSelector:@selector(runStep:)]) {
        return [step  runStep:context];
    }
    
    return YES;
}


+ (void)performStepWillTerminateIfAvailable:(KIFStepProtocol *)step
              withContext:(KIFContext *)context
{
    if ([step  respondsToSelector:@selector(stepWillTerminate:)]) {
        [step  stepWillTerminate:context];
    }
}


#pragma mark 


- (BOOL)shouldRunStep:(KIFContext *)context;
{
    return YES;
}


- (BOOL)stepWillBegin:(KIFContext *)context;
{
    return YES;
}


- (BOOL)runStep:(KIFContext *)context;
{
    return YES;
}


- (void)stepWillTerminate:(KIFContext *)context
{
    // Do nothing
}


- (NSString *)stepDescription
{
    return @"";
}


- (NSTimeInterval)stepTimeout
{
    return KIF_DEFAULT_STEP_TIMEOUT;
}


@end
