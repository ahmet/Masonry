//
//  MASConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "MASUtilities.h"

/**
 *	Enables Constraints to be created with chainable syntax
 *  Constraint can represent single NSLayoutConstraint (MASViewConstraint) 
 *  or a group of NSLayoutConstraints (MASComposisteConstraint)
 */
/**
    当前类的设计是为了能够使用链式语法，来表示单个 NSLayoutConstraint (用MASViewConstraint进行了封装)
    或者一组 NSLayoutConstraint (用MASComposisteConstraint)
    注意：这是个抽象基类，不要直接创建实例使用
 */
@interface MASConstraint : NSObject

// Chaining Support

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
/**
    修改这个 NSLayoutConstraint 常量
    只会影响MASConstraints在NSLayoutConstraint设置约束的API中的第一个item(也就是API中的view1)的NSLayoutAttribute参数为
    以下NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight时
 */
- (MASConstraint * (^)(MASEdgeInsets insets))insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
/**
    这个API与上一个API的作用的唯一区别是，设置单个inset属性
 */
- (MASConstraint * (^)(CGFloat inset))inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
/**
    修改这个 NSLayoutConstraint 常量
    只会影响MASConstraints在NSLayoutConstraint设置约束的API中的第一个item(也就是API中的view1)的NSLayoutAttribute参数为
    NSLayoutAttributeWidth, NSLayoutAttributeHeight时
 */
- (MASConstraint * (^)(CGSize offset))sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
/**
    修改这个 NSLayoutConstraint 常量
    只会影响MASConstraints在NSLayoutConstraint设置约束的API中的第一个item(也就是API中的view1)的NSLayoutAttribute参数为
    NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (MASConstraint * (^)(CGPoint offset))centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
/**
    修改这个 NSLayoutConstraint 常量
 */
- (MASConstraint * (^)(CGFloat offset))offset;

/**
 *  Modifies the NSLayoutConstraint constant based on a value type
 */
/**
    基于一个值类型修改NSLayoutConstraint
 */
- (MASConstraint * (^)(NSValue *value))valueOffset;

/**
 *	Sets the NSLayoutConstraint multiplier property
 */
/**
    设置NSLayoutConstraint的乘数因子属性
 */
- (MASConstraint * (^)(CGFloat multiplier))multipliedBy;

/**
 *	Sets the NSLayoutConstraint multiplier to 1.0/dividedBy
 */
/**
    设置NSLayoutConstraint的乘数因子属性为1.0除以以dividedBy为除数的值
 */
- (MASConstraint * (^)(CGFloat divider))dividedBy;

/**
 *	Sets the NSLayoutConstraint priority to a float or MASLayoutPriority
 */
/**
    设置NSLayoutConstraint优先级为一个'浮点数'或者'MASLayoutPriority'
 */
- (MASConstraint * (^)(MASLayoutPriority priority))priority;

/**
 *	Sets the NSLayoutConstraint priority to MASLayoutPriorityLow
 */
/**
    设置NSLayoutConstraint优先级为'MASLayotPriorityLow'
 */
- (MASConstraint * (^)(void))priorityLow;

/**
 *	Sets the NSLayoutConstraint priority to MASLayoutPriorityMedium
 */
/**
    设置NSLayoutConstraint优先级为'MASLayoutPriorityMedium'
 */
- (MASConstraint * (^)(void))priorityMedium;

/**
 *	Sets the NSLayoutConstraint priority to MASLayoutPriorityHigh
 */
/**
    设置NSLayoutConstraint优先级为'MASLayoutPriorityHigh'
 */
- (MASConstraint * (^)(void))priorityHigh;

/**
 *	Sets the constraint relation to NSLayoutRelationEqual
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
/**
    设置这个约束与NSLayoutRelationEqual关联
    返回一个接受如下类型之一作为参数的block：
    MASViewAttribute, UIView, NSValue, NSArray
 */
- (MASConstraint * (^)(id attr))equalTo;

/**
 *	Sets the constraint relation to NSLayoutRelationGreaterThanOrEqual
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
/**
    设置这个约束跟NSLayoutRelationGreaterThanOrEqual
    返回一个接受如下类型之一作为参数的block：
    MASViewAttribute, UIView, NSValue, NSArray
 */
- (MASConstraint * (^)(id attr))greaterThanOrEqualTo;

/**
 *	Sets the constraint relation to NSLayoutRelationLessThanOrEqual
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
/**
    设置这个约束跟NSLayoutRelationLessThanOrEqual
    返回一个接受如下类型之一作为参数的block：
    MASViewAttribute, UIView, NSValue, NSArray
 */
- (MASConstraint * (^)(id attr))lessThanOrEqualTo;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
/**
    可选的语义属性，不会产生什么影响，只为了增加约束的可读性
 */
- (MASConstraint *)with;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
/**
    可选的语义属性，不会产生什么影响，只为了增加约束的可读性
 */
- (MASConstraint *)and;

/**
 *	Creates a new MASCompositeConstraint with the called attribute and reciever
 */
- (MASConstraint *)left;
- (MASConstraint *)top;
- (MASConstraint *)right;
- (MASConstraint *)bottom;
- (MASConstraint *)leading;
- (MASConstraint *)trailing;
- (MASConstraint *)width;
- (MASConstraint *)height;
- (MASConstraint *)centerX;
- (MASConstraint *)centerY;
- (MASConstraint *)baseline;

- (MASConstraint *)firstBaseline;
- (MASConstraint *)lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

/**
    只在iPhone和Apple TV中可用，UIView的默认margin为{8,8,8,8}，
    UIViewControlr的root view的topMargin和bottomMargin为0，而leftMargin和rightMargin可能为16也可能为20
    其他情况可以通过设置layoutMargins而定
    参考:https://developer.apple.com/documentation/uikit/uiview/1622566-layoutmargins
 */
- (MASConstraint *)leftMargin;
- (MASConstraint *)rightMargin;
- (MASConstraint *)topMargin;
- (MASConstraint *)bottomMargin;
- (MASConstraint *)leadingMargin;
- (MASConstraint *)trailingMargin;
- (MASConstraint *)centerXWithinMargins;
- (MASConstraint *)centerYWithinMargins;

#endif


/**
 *	Sets the constraint debug name
 */
/**
    设置constraint的debug名称，如果不设置一般会在console打印出视图对象的内存地址
 */
- (MASConstraint * (^)(id key))key;

// NSLayoutConstraint constant Setters
// for use outside of mas_updateConstraints/mas_makeConstraints blocks
/**
    NSLayoutConstraint常量setter方法
    为了在mas_updateConstraints/mas_makeConstraints的block外部使用
 */
/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInsets:(MASEdgeInsets)insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInset:(CGFloat)inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (void)setSizeOffset:(CGSize)sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects MASConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (void)setCenterOffset:(CGPoint)centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (void)setOffset:(CGFloat)offset;


// NSLayoutConstraint Installation support
// NSLayoutConstraint 支持装载
#if TARGET_OS_MAC && !(TARGET_OS_IPHONE || TARGET_OS_TV)
/**
 *  Whether or not to go through the animator proxy when modifying the constraint
 */
/**
    主要用于MAC上修改约束时通过animator代理做动画
 */
@property (nonatomic, copy, readonly) MASConstraint *animator;
#endif

/**
 *  Activates an NSLayoutConstraint if it's supported by an OS. 
 *  Invokes install otherwise.
 */
/**
    激活当前约束
 */
- (void)activate;

/**
 *  Deactivates previously installed/activated NSLayoutConstraint.
 */
/**
    使当前约束无效，如果支持isActive，则直接通过设置isActive = NO关闭当前约束
    如果不支持isActive，则直接通过-removeConstraint:方法移除当前约束
 */
- (void)deactivate;

/**
 *	Creates a NSLayoutConstraint and adds it to the appropriate view.
 */
/**
    创建一个NSLayoutConstraint并且添加它到合适的view上，具体逻辑看MASViewConstraint的实现
 */
- (void)install;

/**
 *	Removes previously installed NSLayoutConstraint
 */
/**
    移除之前被装载的NSLayoutConstraint，具体逻辑看MASViewConstraint的实现
 */
- (void)uninstall;

@end


/**
 *  Convenience auto-boxing macros for MASConstraint methods.
 *
 *  Defining MAS_SHORTHAND_GLOBALS will turn on auto-boxing for default syntax.
 *  A potential drawback of this is that the unprefixed macros will appear in global scope.
 */
/**
    为MASConstraint方法定义的，便捷的自动装箱宏定义
    定义‘MAS_SHORTHAND_GLOBALS’将为默认语法开启自动装箱功能
    这里有个潜在的缺陷是，没有前缀的宏定义将出现在全局区域中
 
    可能与其他库造成宏的重定义警告
    这里可以看到mas_equalTo调用了equalTo宏，equalTo宏有展开成了mas_equalTo，这里可能给人造成一种迷惑
    认为宏会循环展开下去，其实GCC对于预编译器的说明文档中写到，一个宏只会被展开一次，如果在一个宏展开链中遇到同名
    宏，则直接进行文本替换
    详情可参考：https://gcc.gnu.org/onlinedocs/cpp/Self-Referential-Macros.html#Self-Referential-Macros
 */
#define mas_equalTo(...)                 equalTo(MASBoxValue((__VA_ARGS__)))
#define mas_greaterThanOrEqualTo(...)    greaterThanOrEqualTo(MASBoxValue((__VA_ARGS__)))
#define mas_lessThanOrEqualTo(...)       lessThanOrEqualTo(MASBoxValue((__VA_ARGS__)))

#define mas_offset(...)                  valueOffset(MASBoxValue((__VA_ARGS__)))


#ifdef MAS_SHORTHAND_GLOBALS

#define equalTo(...)                     mas_equalTo(__VA_ARGS__)
#define greaterThanOrEqualTo(...)        mas_greaterThanOrEqualTo(__VA_ARGS__)
#define lessThanOrEqualTo(...)           mas_lessThanOrEqualTo(__VA_ARGS__)

#define offset(...)                      mas_offset(__VA_ARGS__)

#endif


@interface MASConstraint (AutoboxingSupport)

/**
 *  Aliases to corresponding relation methods (for shorthand macros)
 *  Also needed to aid autocompletion
 */
/**
    这三个方法跟equalTo、greaterThanOrEqualTo、lessThanOrEqualTo一致
 */
- (MASConstraint * (^)(id attr))mas_equalTo;
- (MASConstraint * (^)(id attr))mas_greaterThanOrEqualTo;
- (MASConstraint * (^)(id attr))mas_lessThanOrEqualTo;

/**
 *  A dummy method to aid autocompletion
 */
/**
    傀儡方法为了自动补全
 */
- (MASConstraint * (^)(id offset))mas_offset;

@end
