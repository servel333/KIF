//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>
#import "KIFSingleton.h"


#pragma mark -


/*!
 @discussion  Next generation of the main controller.
 */
@interface KIFController : NSObject


KIFSingletonInterface(KIFController, sharedController);


@end
