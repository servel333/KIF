//  Created by Nathan Perry.
//


#import "KIFController.h"


#pragma mark -


@implementation KIFController


KIFSingletonImplementation(KIFController, sharedController);


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


@end
