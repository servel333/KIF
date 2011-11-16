//  Created by Nathan Perry.
//


#import "KIFStep.h"

#import "KIF.h"
#import "KIFMutableStepContext.h"


#pragma mark -


@interface KIFStep ()


+ (BOOL)performShouldRunStepIfAvailable:(NSObject<KIFStepNotifications> *)step
                            withContext:(KIFStepContext *)context;


+ (BOOL)performStepWillBeginIfAvailable:(NSObject<KIFStepNotifications> *)step
                            withContext:(KIFStepContext *)context;


+ (BOOL)performRunStepIfAvailable:(NSObject<KIFStepNotifications> *)step
                      withContext:(KIFStepContext *)context;


+ (void)performStepWillTerminateIfAvailable:(NSObject<KIFStepNotifications> *)step
                                withContext:(KIFStepContext *)context;


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


+ (BOOL)runStep:(NSObject<KIFStepNotifications> *)step
   fromScenario:(KIFScenario *)scenario
 withController:(KIFController *)controller
{
    BOOL success = YES;
    KIFMutableStepContext *context = [KIFMutableStepContext  context];
    
    [context  setController:controller];
    [context  setScenario:scenario];
    [context  setStep:step];
    [context  setFirstRunStep:[[NSDate  date]  timeIntervalSinceReferenceDate]];
    [context  setLastRunStep:[[NSDate  date]  timeIntervalSinceReferenceDate]];
    context.runStepAgain = NO;
    context.error = nil;
    
    
    
    if (context.runStepAgain) {
        // FIXME: Run the step again if no errors.
    }
    
    if (context.error) {
        // FIXME: Write context.error to the log
    }
    
    [context release];
    return success;
}


+ (BOOL)runStep:(NSObject<KIFStepNotifications> *)step
    withContext:(KIFStepContext *)context
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


+ (BOOL)performShouldRunStepIfAvailable:(NSObject<KIFStepNotifications> *)step
          withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(shouldRunStep:)]) {
        return [step  shouldRunStep:context];
    }
    
    return YES;
}


+ (BOOL)performStepWillBeginIfAvailable:(NSObject<KIFStepNotifications> *)step
          withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(stepWillBegin:)]) {
        return [step  stepWillBegin:context];
    }
    
    return YES;
}


+ (BOOL)performRunStepIfAvailable:(NSObject<KIFStepNotifications> *)step
    withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(runStep:)]) {
        return [step  runStep:context];
    }
    
    return YES;
}


+ (void)performStepWillTerminateIfAvailable:(NSObject<KIFStepNotifications> *)step
              withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(stepWillTerminate:)]) {
        [step  stepWillTerminate:context];
    }
}


#pragma mark 


- (BOOL)shouldRunStep:(KIFStepContext *)context;
{
    return YES;
}


- (BOOL)stepWillBegin:(KIFStepContext *)context;
{
    return YES;
}


- (BOOL)runStep:(KIFStepContext *)context;
{
    return YES;
}


- (void)stepWillTerminate:(KIFStepContext *)context
{
    // Do nothing
}


- (NSString *)stepDescription
{
    return @"";
}


- (NSTimeInterval)stepTimeout
{
    return KIF_DEFAULT_TIMEOUT;
}


@end
