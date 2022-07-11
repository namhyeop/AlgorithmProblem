# 채팅 프로젝트 과제

* chatSubject 아래 Lobby 패키지와 server 패키지로 구분되어져있습니다.
* Lobby 패키지 하단에는 두 개의 Client 패키지로 이루어져있습니다.
* 고객 요청에 대한 구현이며 인텔리제이에서 클라이언트 프로세스를 동시에 두 개를 생성할 방법을 찾지 못하여 같은 패키지가 두 개로 이루어져있는것입니다.
* Controller의 9000번 포트로 접근하여 마스터 Thread를 생성하고 마스터 Thread를 통해 각 Slave Thread(채팅방)를 생성하는 로직으로 구현하였습니다.

## Client 패키지
* ClientFrame : 인터페이스 및 응답 이벤트 구현체
* IdFrame : 로그인 아이디 입력 인터페이스
* MainClientFrame : main로직이 담겨있는 파일
* ReadThread : Server로부터의 요청에 응답하는 스레드, 각 Server의 String형을 분석해 명령을 수행
* WriteClass : Server로의 수행 명령을 요청하기 위한 Class

## Sever 패키지
* Controller : 9000번대의 로비를 의미하는 클래스이며 방 만들기 명령어에 대한 요청들을 수행한다.
* Server : Server 객체를 생성합니다. 각 채팅방은 하나의 Server를 의미하며 readThread를 수행하여 Client의 요청을 수행합니다.
* ServerThread : 9000번 접근시 마스터 Thread를 생성합니다. 마스터 Thread는 Sever를 생성하는 특수한 스레드가 동작합니다.

## 테스트 방법
1. Controller를 실행한다.
2. Client Package1의 MainClientFrame을 실행한다.
3. Client Package2의 MainClientFrame을 실행한다.
4. 로비에서 대화(9000번 포트번호)가 정상적으로 이루어지는지 확인한다.
5. 추가적으로 여러 방에 참가하며 대화가 정상적으로 이루어지는 확인한다.
6. 방에 대한 추가와 동기화는 방을 만들었을때만 확인 가능하다.
7. 방 이동시에는 입력한 텍스트가 두 번 나오면 정상정으로 방에 참가한것입니다.
8. 방 만들기는 로비에서만 생성됩니다.(9000번 대에서만 생성가능 == 로비에서만 생성가능)