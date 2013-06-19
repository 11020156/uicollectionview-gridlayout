//
//  VCollectionViewGridLayout.h
//
//  This software is licensed under the Apache 2 license, quoted below.
//
//  Copyright (C) 2012-2013 Vast.com, Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not
//  use this file except in compliance with the License. You may obtain a copy of
//  the License at
//
//  [http://www.apache.org/licenses/LICENSE-2.0]
// 
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
//  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
//  License for the specific language governing permissions and limitations under
//  the License.

/**
 Simple grid layout for UICollectionView that fixes animation issues seen with UICollectionViewFlowLayout.
 Currently supports vertical scrolling only.
 */

#import <UIKit/UIKit.h>
#import "TLIndexPathDataModel.h"

extern NSString *const CSGridLayoutElementKindSectionHeader;

@class VCollectionViewGridLayout;

@protocol VCollectionViewGridLayoutDelegate <UICollectionViewDelegate>

/**
 The layout requires a unique identifier each index path in order to track the 
 movement of items as index paths are inserted, deleted or moved. For example,
 if the collection view is backed by a `TLIndexPathTools` data model, simply
 return the value of `[TLIndexPathDataModel identifierAtIndexPath:]`.
 */
- (id)identifierForItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 The layout requires a unique name for each section in order to track the
 movement of sections as they are inserted, deleted or moved. For example,
 if the collection view is backed by a `TLIndexPathTools` data model, simply
 return the value of `[TLIndexPathDataModel sectionNameForSection:]`.
 */
- (NSString *)sectionNameForSection:(NSInteger)section;

@optional

/**
 Returns the reference size for the specified section. Implement this method if
 the layout will have sections of varying sizes. Otherwise, use the `headerSize` property.
 */
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(VCollectionViewGridLayout*)layout referenceSizeForHeaderInSection:(NSInteger)section;

@end

@interface VCollectionViewGridLayout : UICollectionViewLayout

/**
 Specifies the number of columnn to display.
 */
@property (nonatomic) NSInteger numberOfColumns;

/**
 Specifies the space between rows
 */
@property (nonatomic) CGFloat rowSpacing;

/**
 Specifies the padding placed around each section
 */
@property (nonatomic) UIEdgeInsets sectionInset;

/**
 Specifies the size of the cell (note that variable size cells are not supported).
 */
@property (nonatomic) CGSize itemSize;

/**
 Specifies the header size. For sections of varying size, use the
 `collectionView:layout:referenceSizeForHeaderInSection:` delegate method instead.
 */
@property (nonatomic) CGSize headerSize;

/**
 When set to YES, headers are sticky like `UITableView` header.
 TODO sticky headers are currently broken.
 */
@property (nonatomic) BOOL stickyHeaders;

/**
 A convenience method for copying a layout (currently only copies configuration
 properties, not the actual layout attributes).
 */
+ (VCollectionViewGridLayout *)layoutWithLayout:(VCollectionViewGridLayout *)layout;

@end
