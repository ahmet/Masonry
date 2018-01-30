//
//  MASConstraint+Private.h
//  Masonry
//
//  Created by Nick Tymchenko on 29/04/14.
//  Copyright (c) 2014 cloudling. All rights reserved.
//

#import "MASConstraint.h"

@protocol MASConstraintDelegate;


@interface MASConstraint ()

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
/**
    是否检测现有约束，而不是添加约束
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *	Usually MASConstraintMaker but could be a parent MASConstraint
 */
/**
    通常这个delegate是MASConstraintMaker，但也有可能是一个父MASConstraint
 */
@property (nonatomic, weak) id<MASConstraintDelegate> delegate;

/**
 *  Based on a provided value type, is equal to calling:
 *  NSNumber - setOffset:
 *  NSValue with CGPoint - setPointOffset:
 *  NSValue with CGSize - setSizeOffset:
 *  NSValue with MASEdgeInsets - setInsets:
 */
/**
    基于value参数，等同于调用：
    NSNumber调用 setOffset:
    NSValue用CGPoint调用-setPointOffset:
    NSValue用CGSize调用-setSizeOffset:
    NSValue用MASEdgeInsets调用-setInsets:
 */
- (void)setLayoutConstantWithValue:(NSValue *)value;

@end


@interface MASConstraint (Abstract) // 抽象方法

/**
 *	Sets the constraint relation to given NSLayoutRelation
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
/**
    设置constraint跟给定的NSLayoutRelation的关系
    返回一个接受如下类型值的block:
    MASViewAttribute, UIView, NSValue, NSArray
 */
- (MASConstraint * (^)(id, NSLayoutRelation))equalToWithRelation;

/**
 *	Override to set a custom chaining behaviour
 */
/**
    重写这个方法来设置自定义链行为
 */
- (MASConstraint *)addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end


@protocol MASConstraintDelegate <NSObject>

/**
 *	Notifies the delegate when the constraint needs to be replaced with another constraint. For example
 *  A MASViewConstraint may turn into a MASCompositeConstraint when an array is passed to one of the equality blocks
 */
/**
    通知代理，当这个constraint需要用另外一个constraint替换时。
    例如：一个MASViewConstraint可能被转换成一个MASCompositeConstraint，当一个数组被传给一个等式block时
 */
- (void)constraint:(MASConstraint *)constraint shouldBeReplacedWithConstraint:(MASConstraint *)replacementConstraint;

- (MASConstraint *)constraint:(MASConstraint *)constraint addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end
