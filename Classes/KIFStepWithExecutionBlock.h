//  Created by Nathan Perry.
//


#import "KIFStep-Protocol.h"
#import "KIFTestStepExecutionBlock.h"
#import "KIFStep.h"


@class KIFStep;


@interface KIFStepWithExecutionBlock : NSObject <KIFStep> {
    KIFTestStepExecutionBlock executionBlock;
}


@end
