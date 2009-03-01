//
//  AITwitterAccount.h
//  Adium
//
//  Created by Zachary West on 2009-02-27.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Adium/AIAccount.h>
#import "MGTwitterEngine/MGTwitterEngine.h"

typedef enum {
	AITwitterUnknownType = 0,
	AITwitterValidateCredentials,
	AITwitterDisconnect,
	AITwitterInitialUserInfo,
	AITwitterProfileUserInfo,
	AITwitterProfileStatusUpdates,
	AITwitterUserIconPull,
	AITwitterDirectMessageSend,
	AITwitterSendUpdate,
	AITwitterUpdateDirectMessage,
	AITwitterUpdateFollowedTimeline,
	AITwitterUpdateReplies,
	AITwitterRemoveFollow
} AITwitterRequestType;

#define TWITTER_UPDATE_INTERVAL_MINUTES		10
#define TWITTER_UPDATE_TIMELINE_COUNT		0 // get the default amount

#define TWITTER_INCORRECT_PASSWORD_MESSAGE	AILocalizedString(@"Incorrect username or password","Error message displayed when the server reports username or password as being incorrect.")

#define TWITTER_REMOTE_GROUP_NAME			@"Twitter"
#define TWITTER_TIMELINE_NAME				@"Twitter Timeline"
#define TWITTER_TIMELINE_UID				@"twitter-timeline"

#define TWITTER_PREFERENCE_DATE_DM			@"Direct Messages"
#define TWITTER_PREFERENCE_DATE_TIMELINE	@"Followed Timeline"
#define TWITTER_PREFERENCE_GROUP_UPDATES	@"Twitter Preferences"

// Status Updates
#define TWITTER_STATUS_CREATED				@"created_at"
#define TWITTER_STATUS_USER					@"user"
#define TWITTER_STATUS_UID					@"screen_name"
#define TWITTER_STATUS_TEXT					@"text"

// Direct Messages
#define TWITTER_DM_CREATED					@"created_at"
#define TWITTER_DM_SENDER_UID				@"sender_screen_name"
#define TWITTER_DM_TEXT						@"text"

// User Info
#define TWITTER_INFO_STATUS					@"status"
#define TWITTER_INFO_STATUS_TEXT			@"text"

#define TWITTER_INFO_DISPLAY_NAME			@"name"
#define TWITTER_INFO_UID					@"screen_name"
#define TWITTER_INFO_ICON					@"profile_image_url"

@interface AITwitterAccount : AIAccount <MGTwitterEngineDelegate> {
	MGTwitterEngine		*twitterEngine;
	NSTimer				*updateTimer;
	
	AIChat				*timelineChat;
	
	BOOL				followedTimelineCompleted;
	BOOL				repliesCompleted;
	NSMutableArray		*queuedUpdates;
	NSMutableArray		*queuedDM;
	
	NSMutableDictionary	*pendingRequests;
}

@end