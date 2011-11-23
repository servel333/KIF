//  Created by Nathan Perry.
//


#import "KIFStepProvider.h"

#import "KIFMutableContext.h"
#import "KIFStep+Protocol.h"


#pragma mark -


@interface KIFStepProvider ()


//- (BOOL)performStepSelector:(SEL)selector  withContext:(KIFContext *)context;


@end


#pragma mark -


@implementation KIFStepProvider


KIFSingletonImplementation(KIFStepProvider, sharedStepProvider);


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


@end
