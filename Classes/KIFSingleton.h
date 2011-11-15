//  Created by Nathan Perry.
//


/*!
 @abstract  Helps define the interface of a singleton.
 @param  TYPE  The type of this singleton.
 @param  NAME  The name of the singleton accessor.  Must match the name used in the implementation.
 @discussion
 Typcially the NAME is something like 'sharedThing' where 'Thing' is the prefix-removed type name of the class.
 */
#define KIFSingletonInterface(TYPE, NAME) \
+ (TYPE *)NAME;


/*!
 @abstract  Helps define the implementation of a singleton.
 @param  TYPE  The type of this singleton.
 @param  NAME  The name of the singleton accessor.  Must match the name used in the interface.
 @discussion
 Typcially the NAME is something like 'sharedThing' where 'Thing' is the prefix-removed type name of the class.
 */
#define KIFSingletonImplementation(TYPE, NAME) \
static TYPE *__ ## NAME; \
\
\
+ (void)initialize \
{ \
    static BOOL initialized = NO; \
    if(!initialized) \
    { \
        initialized = YES; \
        __ ## NAME = [[TYPE alloc] init]; \
    } \
} \
\
\
+ (TYPE *)NAME \
{ \
    return __ ## NAME; \
}
