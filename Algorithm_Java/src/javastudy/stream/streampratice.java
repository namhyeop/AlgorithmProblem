package javastudy.stream;

import java.lang.reflect.Array;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

public class streampratice {
    public static void main(String[] args) {
        int arr[] = {1,1,3,222,0,45,32,50};
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < 10; i++){
            list.add(i);
        }

        //숫자 배열 stream 타입 처리를 위한 boxed()사용
        System.out.println(Arrays.stream(arr).boxed());

        //배열 크기 , 컬렉션 크기 확인 예제
        System.out.println("배열 크기, 컬렉션 크기 확인");
        System.out.println(Arrays.stream(arr).count());
        System.out.println(list.stream().count());

        //sorted 정렬
        System.out.println("sorted 정렬 예제");
        System.out.println(Arrays.stream(arr).boxed().sorted().collect(Collectors.toList()));
        System.out.println(list.stream().sorted().collect(Collectors.toList()));

        //sorted 역정렬
        System.out.println("sorted 역정렬");
        System.out.println(Arrays.stream(arr).boxed().sorted(Comparator.reverseOrder()).collect(Collectors.toList()));
        System.out.println(list.stream().sorted(Comparator.reverseOrder()).collect(Collectors.toList()));

        //findFirst 처음값
        System.out.println("skip(배열크기 -1).findfirst는 스트림 마지막 값");
        System.out.println(Arrays.stream(arr).skip(arr.length -1).findFirst().getAsInt());
        System.out.println(list.stream().skip(list.size() - 1).findFirst().get());

        //skip(값), 값만큼 개수 생략하기
        System.out.println("skip(값), 값만큼 생략하기");
        System.out.println(Arrays.stream(arr).boxed().skip(1).collect(Collectors.toList()));
        System.out.println(list.stream().skip(1).collect(Collectors.toList()));

        //limit(값), 값만큼만 뽑아오기
        System.out.println("limit(값), 값 인덱스 전까지 만큼만 뽑아오기");
        System.out.println(Arrays.stream(arr).boxed().limit(3).collect(Collectors.toList()));
        System.out.println(list.stream().limit(3).collect(Collectors.toList()));

        //distinct(), 중복 생략
        System.out.println("distinct(), 중복 생략");
        System.out.println(Arrays.stream(arr).boxed().distinct().collect(Collectors.toList()));
        System.out.println(list.stream().distinct().collect(Collectors.toList()));

        //max(),최대값 찾기
        System.out.println("max(),최대값 찾기");
        System.out.println(Arrays.stream(arr).boxed().max(Integer::compare).get());
        System.out.println(list.stream().max(Integer::compare).get());

        //min(),최소값 찾기
        System.out.println("min(),최소값 찾기");
        System.out.println(Arrays.stream(arr).boxed().min(Integer::compare).get());
        System.out.println(list.stream().min(Integer::compare).get());

        //average(), 평균
        System.out.println("average() 평균");
        System.out.println(Arrays.stream(arr).average().getAsDouble());
        System.out.println(list.stream().mapToDouble(Integer::doubleValue).average().getAsDouble());

        //sum(), 합계
        System.out.println("sum(), 합계");
        System.out.println(Arrays.stream(arr).sum());
        System.out.println(list.stream().mapToInt(Integer::intValue).sum());

        //람다를 이용한 map가공(자료구조 map x)
        System.out.println("map 1이면 true, 아니면 false");
        System.out.println(Arrays.stream(arr).boxed().map(val->val==1).collect(Collectors.toList()));
        System.out.println(list.stream().map(val->val==1).collect(Collectors.toList()));

        //map 값마다 10 더하기 예제
        System.out.println("map 값마다 10 더하기 예제");
        System.out.println(Arrays.stream(arr).boxed().map(val -> val + 10).collect(Collectors.toList()));
        System.out.println(Arrays.stream(arr).boxed().map(val -> val = val + 10).collect(Collectors.toList()));
        System.out.println(list.stream().map(val -> val = val + 10).collect(Collectors.toList()));

        //map 값 반올림 예제
        System.out.println("map 값 반올림 예제");
        System.out.println(Arrays.stream(arr).boxed().map(val -> Math.round(val * 10)/10.0).collect(Collectors.toList()));
        System.out.println(list.stream().map(val -> Math.round(val * 10)/10.0).collect(Collectors.toList()));

        //foreach, 모든 값마다 입력한 내용을 수행한다
        System.out.println("forEach, 모든 값마다 입력한 내용 수행");
        Arrays.stream(arr).boxed().forEach(val -> System.out.println("For each 출력 " + val));
        list.stream().forEach(val -> System.out.println("for each 출력 " + val));

        //anyMatch, 스트림에서 조건이 하나라도 만족하면 true 반환
        System.out.println("anyMatch, 스트림에서 조건이 하나라도 만족하면 true 반환");
        System.out.println(Arrays.stream(arr).boxed().anyMatch(val -> val == 0));
        System.out.println(list.stream().anyMatch(val -> val == 0));

        //nonMatch, 스트림에서 조건이 하나라도 안맞으면 true
        System.out.println("nonMatch, 스트림에서 조건이 하나라도 안맞으면 true");
        System.out.println(Arrays.stream(arr).noneMatch(val -> val==99));
        System.out.println(list.stream().noneMatch(val -> val == 99));

        //allMatch, 스트림의 값이 모두 조건과 맞으면 true
        System.out.println("allMatch, 스트림의 값이 모두 조건과 맞으면 true");
        System.out.println(Arrays.stream(arr).allMatch(val -> val == 1));
        System.out.println(list.stream().allMatch(val -> val == 1));

        //filter, 특정 값만 허용
        System.out.println("filter, 특정 값만 허용");
        System.out.println(Arrays.stream(arr).boxed().filter(val -> val == 222 || val == 1).collect(Collectors.toList()));
        System.out.println(list.stream().filter(val -> val == 222).collect(Collectors.toList()));

        //reduce, 스트림 값을 다 합치는 예제
        System.out.println("reduce, 스트림 값을 다 합치는 예제");
        System.out.println(Arrays.stream(arr).reduce(10,Integer::sum));
        System.out.println(list.stream().reduce(0,Integer::sum));

        //반환 예제
        //배열로 반환하기 예제
        System.out.println(Arrays.stream(arr).boxed().distinct());
        System.out.println(list.stream().max(Integer::compare));

        //배열로 반환
        int[] arr1 = Arrays.stream(arr).distinct().toArray();
        //list로 반환
        List<Integer> list1 = Arrays.stream(arr).boxed().distinct().collect(Collectors.toList());
        int value1 = list.stream().max(Integer::compare).get();
        long collect = list.stream().collect(Collectors.counting());

        String strArr[] = {"10", "20", "30"};

        // 컬렉션 내 모든 값을 |를 붙여서 반환하기
        // | 없이 만들려면 ""로 변경
        System.out.println(Arrays.stream(strArr).collect(Collectors.joining("|")));

        // Int 형태로 평균값 반환 (배열이 String일 경우)
        Double val4 = Arrays.stream(strArr)
                .collect(Collectors.averagingInt(val -> Integer.parseInt(val)));

        // Long 형태로 평균값 반환(배열이 String일 경우)
        Double val5 = Arrays.stream(strArr)
                .collect(Collectors.averagingDouble(val -> Double.parseDouble(val)));

        // Long 형태로 평균값 반환(배열이 String일 경우)
        Double val6 = Arrays.stream(strArr)
                .collect(Collectors.averagingLong(val -> Long.parseLong(val)));
        // 값 확인
        System.out.println("val4 : " + val4);
        System.out.println("val5 : " + val5);
        System.out.println("val6 : " + val6);

        String[] getGroupParti = {"zeebra", "cobra", "cobra", "dog"};

        // 이름, 갯수로 Group으로 묶어 담아줌
        Map<String, Long> map = Arrays.stream(getGroupParti)
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        System.out.println("cobra : " + map.get("cobra"));

        // 조건에 맞으면 true, 아니면 false의 list 형태로 담아줌
        Map<Boolean, List<String>> map2 = Arrays.stream(getGroupParti)
                .collect(Collectors.partitioningBy(val -> val == "cobra"));
        System.out.println(map2.get(false));

        String sibal = "123";
        System.out.println(sibal.charAt(2));

    }
}
