//
// Created by hyeonbae kim on 2026. 11. 17..
//

#ifndef C_STUDY_SPEAKER_H
#define C_STUDY_SPEAKER_H

/*
접근제어자를 사용하면 해당 클래스 외부에서 특정 필드나 메서드에 접근하는 것을 허용하거나 제한할 수 있다.
스피커의 음량이 절대로 100이 넘어가면 안된다는 요구사항이 있다.
스피커 객체를 만든다. 음량 업, 다운, 현재음량 확인하는 기능
 */
class Speaker {
public:
    int volume;

    Speaker(int volume);

    void volumeUp();

    void showVolume();
};


#endif //C_STUDY_SPEAKER_H
