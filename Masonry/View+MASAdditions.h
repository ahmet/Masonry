//
//  UIView+MASAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASUtilities.h"
#import "MASConstraintMaker.h"
#import "MASViewAttribute.h"

/**
 *	Provides constraint maker block
 *  and convience methods for creating MASViewAttribute which are view + NSLayoutAttribute pairs
 */
/**
    提供约束maker block块和创建MASViewAttribute的便捷方法
 */
@interface MAS_VIEW (MASAdditions)

/**
 *	following properties return a new MASViewAttribute with current view and appropriate NSLayoutAttribute
 */
/**
    下面的属性返回一个新的MASViewAttribute，用当前view和适当的NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_left;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_top;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_right;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_bottom;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_leading;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_trailing;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_width;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_height;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerX;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerY;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_baseline;
@property (nonatomic, strong, readonly) MASViewAttribute *(^mas_attribute)(NSLayoutAttribute attr);

@property (nonatomic, strong, readonly) MASViewAttribute *mas_firstBaseline;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) MASViewAttribute *mas_leftMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_rightMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_topMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_bottomMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_leadingMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_trailingMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerXWithinMargins;
@property (nonatomic, strong, readonly) MASViewAttribute *mas_centerYWithinMargins;

/**
 以下属性只用于second view，因为如果用于first view的话，无法调用make、remake、update方法
 */
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuide NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideLeading NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideTrailing NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideLeft NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideRight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideTop NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideBottom NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideWidth NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideHeight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideCenterX NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) MASViewAttribute *mas_safeAreaLayoutGuideCenterY NS_AVAILABLE_IOS(11.0);

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id mas_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
/**
    查找当前视图和参数中输入的视图之间最近的公共父视图
    如果找不到就返回nil
 */
- (instancetype)mas_closestCommonSuperview:(MAS_VIEW *)view;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created MASConstraints
 */
/**
 NS_NOESCAPE: 作用是告诉编译器，block参数在mas_makeConstraints方法返回之前就会执行完毕，而不是被保存起来在之后的某个时候再执行
            编译器知道之后，就会相应的做一些优化，例如去掉一些多余的对self的捕获、retain、release操作。因为block的存活范围仅限
            与本方法内，没有必要再在block内保留self了。
 详情内容参考：https://github.com/apple/swift-evolution/blob/master/proposals/0012-add-noescape-to-public-library-api.md
 */
- (NSArray *)mas_makeConstraints:(void(NS_NOESCAPE ^)(MASConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
/**
    用被调用的view创建一个MASConstraintMaker.
    一旦block执行结束，所有block内设置的约束值会被添加到这个被调用的view上，或者适当的父view上.
    如果一个约束已经存在，那么它会被更新后的约束代替.
 */
- (NSArray *)mas_updateConstraints:(void(NS_NOESCAPE ^)(MASConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
/**
    创建一个MASConstraintMaker用被调用的view.
    一旦block执行结束，所有block内设置的约束值会被添加到这个被调用的view上，或者适当的父view上.
    所有预先被装载的约束会被移除，然后重新按照block内的约束代替.
 */
- (NSArray *)mas_remakeConstraints:(void(NS_NOESCAPE ^)(MASConstraintMaker *make))block;

@end
