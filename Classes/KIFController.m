//  Created by Nathan Perry.
//


#import "KIFController.h"


#pragma mark -


@implementation KIFController


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


KIFSingletonImplementation(KIFController, sharedController);


@end
