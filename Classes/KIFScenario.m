//  Created by Nathan Perry.
//


#import "KIFScenario.h"

#import "KIFStep-Protocol.h"


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


- (KIFStepProtocol *)getNextStep
{
    // FIXME: get the next step in the sequence.
    return nil;
}


@end
