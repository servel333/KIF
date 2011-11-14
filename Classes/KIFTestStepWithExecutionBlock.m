//  Created by Nathan Perry.
//


#import "KIFTestStepWithExecutionBlock.h"

#import "KIFTestContext.h"


#pragma mark -


@interface KIFTestStepWithExecutionBlock () {
}


@property (nonatomic, copy) KIFTestStepExecutionBlock executionBlock;


@end


#pragma mark -


@implementation KIFTestStepWithExecutionBlock


- (id)init {
    
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


@synthesize executionBlock;


+ (BOOL)testStepResult:(KIFTestStepResult)testStepResult  andError:(NSError *)error  toContext:(KIFTestContext *)context {
    
    BOOL succeeded = NO;
    
    switch (testStepResult) {
        case KIFTestStepResultSuccess:
            succeeded = YES;
            context.error = error;
            break;
            
        case KIFTestStepResultFailure:
            succeeded = NO;
            context.error = error;
            break;
            
        case KIFTestStepResultWait:
            succeeded = YES;
            context.error = error;
            context.runStepAgain = YES;
            break;
            
        default:
            break;
    }
    
    return succeeded;
}


- (BOOL)runStep:(KIFTestContext *)context {
    
    KIFTestStepResult result = KIFTestStepResultFailure;
    NSError *error = nil;
    
    if (self.executionBlock) {
        @try {
            result = self.executionBlock(self, &error);
        }
        @catch (id exception) {
            // We need to catch exceptions and things like NSInternalInconsistencyException, which is actually an NSString
            //KIFTestCondition(NO, error, @"Step threw exception: %@", exception);
        }
    }
    
    return [[self class]  testStepResult:result  andError:error  toContext:context];
}


@end
