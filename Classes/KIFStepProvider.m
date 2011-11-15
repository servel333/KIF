//  Created by Nathan Perry.
//


#import "KIFStepProvider.h"

#import "KIFMutableStepContext.h"
#import "KIFStepNotifications.h"


#pragma mark -


@interface KIFStepProvider ()


- (BOOL)performStepSelector:(SEL)selector  withContext:(KIFStepContext *)context;


@end


#pragma mark -


@implementation KIFStepProvider


KIFSingletonImplementation(KIFStepProvider, sharedStepProvider);


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


- (BOOL)runStep:(KIFStep *)step
   fromScenario:(KIFScenario *)scenario
 withController:(KIFController *)controller
{
    BOOL success = YES;
    KIFMutableStepContext *context = [[KIFMutableStepContext alloc] init];
    
    [context  setController:controller];
    [context  setScenario:scenario];
    [context  setStep:step];
    [context  setFirstRunStep:[[NSDate  date]  timeIntervalSinceReferenceDate]];
    [context  setLastRunStep:[[NSDate  date]  timeIntervalSinceReferenceDate]];
    context.runStepAgain = NO;
    context.error = nil;
    
    if ([step  respondsToSelector:@selector(shouldRunStep:)]) {
        if (![step  shouldRunStep:context]) {
            // The step has been cancelled.
            // Run stepWillTerminate, clean up and go to the next step.
        }
    }
    
    if ([step  respondsToSelector:@selector(stepWillBegin:)]) {
        if (![step  stepWillBegin:context]) {
            // The step has failed.
            // Run stepWillTerminate, clean up and fail the scenario.
        }
    }
    
    if ([step  respondsToSelector:@selector(runStep:)]) {
        if (![step  runStep:context]) {
            // The step has failed.
            // Run stepWillTerminate, clean up and fail the scenario.
        }
    }
    
    if ([step  respondsToSelector:@selector(stepWillTerminate:)]) {
        [step  stepWillTerminate:context];
    }
    
    if (context.runStepAgain) {
        // FIXME: Run the step again if no errors.
    }
    
    if (context.error) {
        // FIXME: Write context.error to the log
    }
    
    [context release];
}


- (BOOL)shouldRunStep:(KIFStep *)step
          withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(shouldRunStep:)]) {
        return [step  shouldRunStep:context];
    }
    
    return YES;
}


- (BOOL)stepWillBegin:(KIFStep *)step
          withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(stepWillBegin:)]) {
        return [step  stepWillBegin:context];
    }
    
    return YES;
}


- (BOOL)runStep:(KIFStep *)step
          withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(runStep:)]) {
        return [step  runStep:context];
    }
    
    return YES;
}


- (BOOL)stepWillTerminate:(KIFStep *)step
          withContext:(KIFStepContext *)context
{
    if ([step  respondsToSelector:@selector(stepWillTerminate:)]) {
        [step  stepWillTerminate:context];
    }
}


@end
