//  Created by Nathan Perry.
//


#import <Foundation/Foundation.h>
#import "KIFSingleton.h"


#pragma mark -


/*!
 @abstract  Responsible for providing the functionality to run steps.
 */
@interface KIFStepProvider : NSObject


KIFSingletonInterface(KIFStepProvider, sharedStepProvider);


@end
