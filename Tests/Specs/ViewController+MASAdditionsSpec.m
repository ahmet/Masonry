//
//  ViewController+MASAdditionsSpec.m
//  Masonry
//
//  Created by Craig Siemens on 2015-06-23.
//
//

#import "ViewController+MASAdditions.h"
#import "View+MASAdditions.h"

SpecBegin(ViewController_MASAdditions)

- (void)testLayoutGuideConstraints {
#ifdef MAS_VIEW_CONTROLLER
    MAS_VIEW_CONTROLLER *vc = [MAS_VIEW_CONTROLLER new];
    MAS_VIEW *view = [MAS_VIEW new];
    
    [vc.view addSubview:view];
    
    [view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(vc.mas_topLayoutGuide);
        make.bottom.equalTo(vc.mas_bottomLayoutGuide);
    }];
    // 这里为什么会是6个约束?
    // 因为约束vc的topLayoutGuide的时候首先默认为vc创建topLayoutGuide并进行top和height的约束
    // 然后，再约束view对于topLayout的bottom的约束
    expect(vc.view.constraints).to.haveCountOf(6);
#endif
}

SpecEnd
