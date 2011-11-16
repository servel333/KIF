//  Created by Nathan Perry.
//


#import "KIFStepContext.h"

#import "KIF.h"


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
    
    [super dealloc];
}


#pragma mark Convenience constructors


+ (id)context
{
    return [[[self alloc] init] autorelease];
}


#pragma mark Properties


@synthesize controller = _controller;
@synthesize scenario = _scenario;
@synthesize step = _step;
@synthesize firstRanStep = _firstRanStep;
@synthesize lastRanStep = _lastRanStep;
@synthesize runStepAgain = _runStepAgain;
@synthesize error = _error;


@end
