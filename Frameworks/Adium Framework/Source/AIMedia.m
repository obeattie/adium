//
//  AIMedia.m
//  Adium
//
//  Created by Zachary West on 2009-12-09.
//  Copyright 2009  . All rights reserved.
//

#import "AIMedia.h"
#import <Adium/AIAccount.h>
#import <Adium/AIListContact.h>

@interface AIMedia()
- (id)initWithContact:(AIListContact *)inListContact
			  onAccount:(AIAccount <AIAccount_Media> *)inAccount;
@end

@implementation AIMedia

+ (AIMedia *)mediaWithContact:(AIListContact *)inListContact
					onAccount:(AIAccount <AIAccount_Media> *)inAccount
{
	return [[[self alloc] initWithContact:inListContact
								onAccount:inAccount] autorelease];
}

@synthesize listContact, mediaType, mediaState, account, protocolInfo, sendProgress, receiveProgress;

- (id)initWithContact:(AIListContact *)inListContact
			  onAccount:(AIAccount *)inAccount
{
	if ((self = [super init])) {
		self.account = inAccount;
		self.listContact = inListContact;
		self.mediaState = AIMediaStateWaiting;
	}
	
	return self;
}

- (void)dealloc
{
	[account destroyMedia:self];
	
	self.account = nil;
	self.listContact = nil;
	
	[super dealloc];
}

- (void)setMediaState:(AIMediaState)inMediaState
{
	mediaState = inMediaState;
	
	[adium.mediaController media:self didSetState:inMediaState];
}

@end
