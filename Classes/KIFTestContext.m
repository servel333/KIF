//  Created by Nathan Perry.
//


#import "KIFTestContext.h"


#pragma mark -


@implementation KIFTestContext


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


#pragma mark properties


@synthesize controller;
@synthesize scenario;
@synthesize step;
@synthesize runStepAgain;
@synthesize error;


@end
