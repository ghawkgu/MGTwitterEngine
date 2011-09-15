//
//  MGTwitterEngineConfig.h
//  MGTwitterEngine
//
//  Created by guyi on 9/13/11.
//  Copyright 2011. All rights reserved.
//

#ifndef USE_LIBXML
//  if you wish to use LibXML, add USE_LIBXML=1 to "Precompiler Macros" in Project Info for all targets
#   define USE_LIBXML 0
#endif

#if YAJL_AVAILABLE
#define API_FORMAT @"json"

#import "MGTwitterStatusesYAJLParser.h"
#import "MGTwitterMessagesYAJLParser.h"
#import "MGTwitterUsersYAJLParser.h"
#import "MGTwitterMiscYAJLParser.h"
#import "MGTwitterSearchYAJLParser.h"
#elif TOUCHJSON_AVAILABLE
#define API_FORMAT @"json"

#import "MGTwitterTouchJSONParser.h"
#else
#define API_FORMAT @"xml"

#if USE_LIBXML
#import "MGTwitterStatusesLibXMLParser.h"
#import "MGTwitterMessagesLibXMLParser.h"
#import "MGTwitterUsersLibXMLParser.h"
#import "MGTwitterMiscLibXMLParser.h"
#import "MGTwitterSocialGraphLibXMLParser.h"
#else
#import "MGTwitterStatusesParser.h"
#import "MGTwitterUsersParser.h"
#import "MGTwitterMessagesParser.h"
#import "MGTwitterMiscParser.h"
#import "MGTwitterSocialGraphParser.h"
#import "MGTwitterUserListsParser.h"
#endif
#endif

#define TWITTER_DOMAIN          @"api.twitter.com/1"
#define TWITTER_UPLOAD_DOMAIN   @"upload.twitter.com/1"

#if YAJL_AVAILABLE || TOUCHJSON_AVAILABLE
#define TWITTER_SEARCH_DOMAIN	@"search.twitter.com"
#endif
#define HTTP_POST_METHOD        @"POST"
#define MAX_MESSAGE_LENGTH      140 // Twitter recommends tweets of max 140 chars
#define MAX_NAME_LENGTH			20
#define MAX_EMAIL_LENGTH		40
#define MAX_URL_LENGTH			100
#define MAX_LOCATION_LENGTH		30
#define MAX_DESCRIPTION_LENGTH	160

#define DEFAULT_CLIENT_NAME     @"MGTwitterEngine"
#define DEFAULT_CLIENT_VERSION  @"1.0"
#define DEFAULT_CLIENT_URL      @"http://mattgemmell.com/source"
#define DEFAULT_CLIENT_TOKEN	@"mgtwitterengine"

#define URL_REQUEST_TIMEOUT     25.0 // Twitter usually fails quickly if it's going to fail at all.