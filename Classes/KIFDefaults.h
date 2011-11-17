//  Created by Nathan Perry.
//


/*!
 @define  KIF_DOMAIN
 @abstract  The default step timeout in seconds for a step
 */
#define KIF_DEFAULT_STEP_TIMEOUT  (10.0)


// I'm unsure if a scenario should have a timeout, other than (number of steps * each steps timeout).
/* !
 @define  KIF_DOMAIN
 @abstract  The default step timeout in seconds for a step
 * /
#define KIF_DEFAULT_SCENARIO_TIMEOUT  (5 * 60.0)
// */


/*!
 @define  KIF_DOMAIN
 @abstract  The domain string for KIF.
 @discussion  This is used in places like [NSError initWithDomain:KIF_DOMAIN ...
 */
#define KIF_DOMAIN  (@"KIF")