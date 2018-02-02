//
//  MASViewConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASViewAttribute.h"
#import "MASConstraint.h"
#import "MASLayoutConstraint.h"
#import "MASUtilities.h"

/**
 *  A single constraint.
 *  Contains the attributes neccessary for creating a NSLayoutConstraint and adding it to the appropriate view
 */
/**
    MASConstraint子类，标识单个constraint
    包括创建NSLayoutConstraint所必须的属性，并且添加它到适当的view上
 */
@interface MASViewConstraint : MASConstraint <NSCopying>

/**
 *	First item/view and first attribute of the NSLayoutConstraint
 */
/**
    NSLayoutConstraint的第一个item/view1和第一个属性/attr1
 */
@property (nonatomic, strong, readonly) MASViewAttribute *firstViewAttribute;

/**
 *	Second item/view and second attribute of the NSLayoutConstraint
 */
/**
    NSLayoutConstraint的第二个item/view2和第二个属性/attr2
 */
@property (nonatomic, strong, readonly) MASViewAttribute *secondViewAttribute;

/**
 *	initialises the MASViewConstraint with the first part of the equation
 *
 *	@param	firstViewAttribute	view.mas_left, view.mas_width etc.
 *
 *	@return	a new view constraint
 */
/**
    初始化这个MASViewConstraint用等式的第一部分
 */
- (id)initWithFirstViewAttribute:(MASViewAttribute *)firstViewAttribute;

/**
 *  Returns all MASViewConstraints installed with this view as a first item.
 *
 *  @param  view  A view to retrieve constraints for.
 *
 *  @return An array of MASViewConstraints.
 */
/**
    返回所有在第一个item的view装载的MASViewConstraint
    参数view是为了用于检索绑定的constraints
 */
+ (NSArray *)installedConstraintsForView:(MAS_VIEW *)view;

@end
