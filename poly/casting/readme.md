업캐스팅은 부모+객체 있는걸 부모로만 캐스팅하는거(위로 캐스팅한다)
업캐스팅은 부모는 마음이 넓어서 자식을 담을 수 있다.
Child* child = new Child();
Parent* parent = child;
child는 Child객체를 포인팅하고 Child객체는 Parent와 Child모두 갖고 있음. 그래서 Parent* 포인팅이 암시적으로 가능한 것

다운캐스팅은 부모있는걸 부모+객체로 캐스팅하는거(아래까지 캐스팅한다)
다운캐스팅은 자식이 부모를 담는것이다. 위험함
그래서 다운캐스팅이 위험해서 dynamic_cast해야함

Parent* parent = new Child();
여기서 원래 위에서 아래를 접근할 수 없으므로
parent -> childMethod(); 가 안되는데
if(Child* child = dynamic_cast<Child*>parent)
    child -> childMethod();
로 접근할 수 있게 하는것.