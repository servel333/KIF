//  Created by Nathan Perry.
//


#import "KIFScenario.h"

#import "KIFStepNotifications.h"


@implementation KIFScenario


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


#pragma mark Properties


@synthesize steps = _steps;


#pragma mark Step progression


- (KIFStepNotifications *)getNextStep
{
    
}


@end
