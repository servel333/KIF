//  Created by Nathan Perry.
//


#import "KIFStepContext.h"

#import "KIFStepContextDelegate.h"
#import "KIFController.h"
#import "KIFScenario.h"
#import "KIFStepNotifications.h"


#pragma mark -


@implementation KIFStepContext


- (id)init
{
    self = [super init];
    if (self) {
        
        // Initialization code here.
        _controller = nil;
        _scenario = nil;
        _step = nil;
        _firstRanStep = 0;
        _lastRanStep = 0;
        _runStepAgain = NO;
        _error = nil;
        
    }
    
    return self;
}


- (void)dealloc {

    [_controller release];
    [_scenario release];
    [_step release];

}


#pragma mark properties


@synthesize controller = _controller;
@synthesize scenario = _scenario;
@synthesize step = _step;
@synthesize firstRanStep = _firstRanStep;
@synthesize lastRanStep = _lastRanStep;
@synthesize runStepAgain = _runStepAgain;
@synthesize error = _error;


@end
