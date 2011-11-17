//  Created by Nathan Perry.
//


#import "KIFUserData.h"


@interface KIFUserData ()


@property (nonatomic, readonly) NSMutableDictionary *dictionary;


@end


#pragma mark -


@implementation KIFUserData


- (id)init
{
    self = [super init];
    if (self) {
        
        // Initialization code here.
        _dictionary = [[NSDictionary  alloc]  init];
        
    }
    
    return self;
}


- (void)dealloc
{
    [_dictionary  release];
    [super  dealloc];
}


#pragma mark Properties


@synthesize dictionary = _dictionary;


#pragma mark KIFUserData (NSDictionaryMethods)


- (NSArray *)allKeys
{
    return [self.dictionary  allKeys];
}


- (NSArray *)allKeysForObject:(KIFUserDataValueType)anObject
{
    return [self.dictionary  allKeysForObject:anObject];
}


- (NSArray *)allValues
{
    return [self.dictionary  allValues];
}


- (NSEnumerator *)objectEnumerator
{
    return [self.dictionary  objectEnumerator];
}


- (NSArray *)objectsForKeys:(NSArray *)keys notFoundMarker:(KIFUserDataValueType)marker
{
    return [self.dictionary  objectsForKeys:keys  notFoundMarker:marker];
}


- (NSArray *)keysSortedByValueUsingSelector:(SEL)comparator
{
    return [self.dictionary  keysSortedByValueUsingSelector:comparator];
}


- (void)getObjects:(KIFUserDataValueType *)objects andKeys:(KIFUserDataKeyType *)keys
{
    return [self.dictionary  getObjects:objects  andKeys:keys];
}


- (void)removeObjectForKey:(KIFUserDataKeyType)aKey
{
    return [self.dictionary  removeObjectForKey:aKey];
}


- (void)setObject:(KIFUserDataValueType)anObject forKey:(KIFUserDataKeyType)aKey
{
    return [self.dictionary  setObject:anObject  forKey:aKey];
}


- (void)addEntriesFromDictionary:(NSDictionary *)otherDictionary
{
    return [self.dictionary  addEntriesFromDictionary:otherDictionary];
}


- (void)removeAllObjects
{
    return [self.dictionary  removeAllObjects];
}


- (void)removeObjectsForKeys:(NSArray *)keyArray
{
    return [self.dictionary  removeObjectsForKeys:keyArray];
}


- (void)setDictionary:(NSDictionary *)otherDictionary
{
    return [self.dictionary  setDictionary:otherDictionary];
}


@end
