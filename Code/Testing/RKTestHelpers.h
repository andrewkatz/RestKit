//
//  RKTestHelpers.h
//  RestKit
//
//  Created by Blake Watters on 10/2/12.
//  Copyright (c) 2012 RestKit. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>

#ifdef _COREDATADEFINES_H
#if __has_include("RKCoreData.h")
#define RKCoreDataIncluded
#endif
#endif

@class RKRoute, RKObjectManager;

/**
 The `RKTestHelpers` class provides a number of helpful utility methods for use in unit or integration tests for RestKit applications.
 */
@interface RKTestHelpers : NSObject

///-----------------------------
/// @name Working with the Cache
///-----------------------------

/**
 Disables caching by setting a new `[NSURLCache sharedURLCache]` instance in which the memory and disk limits have been set to zero.
 */
+ (void)disableCaching;

/**
 Creates, stores, and returns a `NSCachedURLResponse` object containing an `NSHTTPURLResponse` for the given request with a 200 (OK) status code.
 
 @param request The request to cache the response for.
 @param responseData The response data to be stored in the cache.
 @return The cached URL response that was stored to the cache.
 */
+ (NSCachedURLResponse *)cacheResponseForRequest:(NSURLRequest *)request withResponseData:(NSData *)responseData;

/**
 Creates, stores, and returns a `NSCachedURLResponse` object containing an `NSHTTPURLResponse` for the given URL and HTTP method with the given response data and a 200 (OK) status code.
 
 @param URL The URL to cache the response for.
 @param HTTPMethod The HTTP method of the request (i.e. 'GET', 'POST', 'PUT', 'PATCH', or 'DELETE').
 @param responseData The response data to be stored in the cache.
 @return The cached URL response that was stored to the cache.
 */
+ (NSCachedURLResponse *)cacheResponseForURL:(NSURL *)URL HTTPMethod:(NSString *)HTTPMethod headers:(NSDictionary *)requestHeaders withData:(NSData *)responseData;

@end
