//
//  ESPurpleAIMAccount.h
//  Adium
//
//  Created by Evan Schoenberg on 2/23/05.
//  Copyright 2006 The Adium Team. All rights reserved.
//

#import "CBPurpleOscarAccount.h"

@interface ESPurpleAIMAccount : CBPurpleOscarAccount {

}

@end

@interface ESPurpleAIMAccount (Informal)
- (void)updateInfo:(AIListContact *)theContact;
- (void)directIMConnected:(AIListContact *)theContact;
- (void)directIMDisconnected:(AIListContact *)theContact;
@end
