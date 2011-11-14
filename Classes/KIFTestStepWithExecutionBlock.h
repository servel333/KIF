//  Created by Nathan Perry.
//


#import "KIFTypes.h"
#import "KIFTestStepDelegate.h"


@interface KIFTestStepWithExecutionBlock : NSObject <KIFTestStepDelegate> {
    KIFTestStepExecutionBlock executionBlock;
}


@end
