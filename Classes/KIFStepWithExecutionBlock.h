//  Created by Nathan Perry.
//


#import "KIFStepNotifications.h"
#import "KIFTestStepExecutionBlock.h"
#import "KIFStep.h"


//@class KIFStep;


@interface KIFStepWithExecutionBlock : KIFStep <KIFStepNotifications> {
    KIFTestStepExecutionBlock executionBlock;
}


@end
