/*
This file is part of TrenchBroom.

TrenchBroom is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TrenchBroom is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
*/

#import "PakDirectoryEntry.h"


@implementation PakDirectoryEntry

- (id)initWithName:(NSString *)theName address:(int)theAddress size:(int)theSize {
    NSAssert(theName != nil, @"name must not be nil");
    
    if (self = [self init]) {
        name = [theName retain];
        address = theAddress;
        size = theSize;
    }
    
    return self;
}

- (void)dealloc {
    [name release];
    [super dealloc];
}

- (NSString *)name {
    return name;
}

- (NSData *)entryDataFromHandle:(NSFileHandle *)theHandle {
    NSAssert(theHandle != nil, @"handle must not be nil");
    [theHandle seekToFileOffset:address];
    return [theHandle readDataOfLength:size];
}

@end
