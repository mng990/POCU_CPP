
## ✅ Udemy POCU_C++ 완강

<br><br/>

🎯 주요했던 학습 내용 (주로 모던 C++)
1. 가상 테이블
   - 특정 클래스의 가상 함수들의
     주소값을 가지고 있는 리스트
     <br></br>
2. 스마트 포인터
   - RAII: "개체의 생성은 자원의 획득과 같다."는 의미를 가진 디자인 패턴<br>
           생성된 개체는 반드시 자원을 소유하고 있어야 함
   - unique_ptr: 원시 포인터의 소유자가 하나만 존재하는 스마트 포인터<br>
                 rvalue 레퍼런스를 통해 이동(std::move)<br>
                 원시 포인터의 공유를 막기 위해 반드시 make_unique()로 생성을 권장 (C++14)<br>
                 원시 포인터가 공유되는 경우, 메모리의 중복 삭제가 발생할 수 있음
   - sharaed_ptr: Reference counting으로 생명 주기를 관리
   - weak_ptr: RF counting에 영향을 주지 않는 weak counting으로 shared_ptr 복사에 용이
     <br></br>
3. rvalue
   - 주소가 존재하지 않는 값
   - lvalue로 할당되는 값으로, 할당 이후 휘발되는 성질을 가짐
   - std::move를 사용해 lvalue를 rvalue 레퍼런스로 변경한 경우<br>
     원칙적으로 이동 후 rvalue에 저장된 값은 모두 삭제시켜야 함
   - 이동 생성자와 이동 대입에 주로 사용
   - 그러나 함수를 rvalue로 반환하는 것은 매우 느림<br>
     (컴파일러의 RVO 최적화를 깨뜨리기 때문)
     <br></br>
4. 람다식
   - [capture] (parameters) specifiers -> return_type {body}로 구성
   - (장점) 간단한 함수를 빠르게 작성하기엔 유용하나 <br>
     (단점) 재사용성이 낮고 디버깅이 어려움
   - sort, 쓰레드 라이브러리의 conditional_variable::wait에 주로 사용
     <br></br>  
6. 쓰레드 라이브러리
   - C++20 이후로 추가된 멀티 스레딩 라이브러리
   - 모든 OS를 지원하기에 최적화가 잘 되어있지 않음(성능이 낮음)
   - 자주 사용되진 않으나 도입하는 프로젝트가 많아지는 중
