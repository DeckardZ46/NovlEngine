>## 2022/12/7
卡在窗体事件(Window Events)，Debug会有报错，可能需要和Hazel的commit对比看看是不是看视频抄错了：  
https://github.com/TheCherno/Hazel/commit/30516ad7109b016213eb732f14e1c7061c1db603#diff-09bb30867cd02581218bc5ff3b605fd8fe984944d1c7268fc8bc11a0ad464720  

然后Hazel的commit页数书签：  
https://github.com/TheCherno/Hazel/commits/master?after=f8f8e3089b47c8371dc61448c3d47d43cad31079+279&branch=master&qualified_name=refs%2Fheads%2Fmaster  
 
准备先做一点Unity的东西，回来再做这个  

>## 2022/12/8
Bug fixed.

通过event dispatcher分配了WindowCloseEvent来示例如何使用event dispatcher，并且创建相应的响应函数来做出动作

>## 2023/01/18
Layers done.

添加了Layers类，在Application runtime中有多层layer来处理event和渲染。